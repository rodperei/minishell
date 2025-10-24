🔵 **Big C Projects**

**Philosophy**: *Organize for modularity, scalability, and collaboration.*

**Hierarchical structure**: Code is grouped into modules, often with `src/`, `include/`, `lib/`, `tests/`.

**Centralized headers**: Public headers are separated (e.g., `include/`) from private/internal ones.

**Namespaces**: Prefixes or directories prevent name collisions (`net/socket.h` vs `math/vector.h`).

**Build system complexity**: Uses `CMake`, `Meson`, or `autotools` to manage dependencies, portability, install rules.

**Testing & CI**: Often has a `tests/` directory, integration with CI, and separate build configurations (debug/release).

**Encapsulation matters**: Implementation details hidden in `.c` and private headers, only exposing stable APIs.

👉 Example layout:
```
project/
├── include/          # Public headers (API)
│   └── project/
│       ├── foo.h
│       └── bar.h
├── src/              # Implementation
│   ├── include/      # Private headers
│   │   └── foo.h
│   ├── foo.c
│   └── bar.c
├── tests/            # Unit tests
├── docs/             # Documentation
├── CMakeLists.txt    # or Meson.build, configure.ac, etc.
└── examples/         # Example programs
```

⚖️ **Philosophical Split**

**Small project mindset**: "Just get it working. Don’t over-engineer."

**Big project mindset**: "Design for reuse, maintainability, and onboarding of new developers."

Some developers even argue that small projects should **stay flat** until complexity forces restructuring, while others prefer to **start modular** to prevent painful refactoring later.


🔵 **Public vs Private Headers**


In C projects the distinction between public headers and private headers is one of the main organizational principles, especially in larger codebases.

Here’s the breakdown:

🔹 **Public Headers**

**What they are**: Header files that define the **official API** of your library or module.

**Who uses them**: Intended for *external code* (applications or other libraries) that depend on your project.

**What they contain**:

Function prototypes you want to expose

Type definitions (structs, enums, typedefs) that are part of the API

Macros and constants relevant to users

**Where they live**: Typically in a dedicated `include/` directory, often with a namespace folder:
```
include/project/foo.h
include/project/bar.h
```

👉 Example (public `math.h`):
```
#ifndef PROJECT_MATH_H
#define PROJECT_MATH_H

int add(int a, int b);
int multiply(int a, int b);

#endif
```

Users of your library would `#include <project/math.h>`.

🔹 **Private Headers**

**What they are**: Internal header files for your project’s own implementation.

**Who uses them**: Only the project’s source files (`.c`) should include them, not external code.

**What they contain**:

Internal helpers, macros, and inline functions

Internal struct definitions (when you don’t want to expose details publicly)

Static inline functions for performance, debugging utilities, etc.

**Where they live**: Usually in `src/` or `src/include/`, kept separate from public headers:
```
src/internal_math.h
```

👉 Example (private `internal_math.h`):
```
#ifndef INTERNAL_MATH_H
#define INTERNAL_MATH_H

// Internal helper, not part of the public API
static inline int square(int x) {
    return x * x;
}

#endif
```

This header is only used inside the library, not by end-users.

🔄 **Why Separate Them?**

**Encapsulation**: Users only see what they’re supposed to use. Internal details can change without breaking external code.

**Stability**: Public headers define a stable contract. Private headers can evolve more freely.

**Portability & Maintenance**: Helps keep ABI (Application Binary Interface) consistent for shared libraries.

**Clean namespace**: Prevents cluttering users with unnecessary macros, structs, or helper functions.

✅ In short:

**Public headers = your project’s promises to the outside world.**

**Private headers = internal notes and helpers you don’t want others to rely on.**

---

### 1. Commit Message Structure

Each commit message should follow this pattern:

```
<type>[optional scope]: <description>

[optional body]

[optional footer(s)]
```

---

### 2. **Types**

The `<type>` indicates the purpose of the commit. Common ones include:

* **feat**: A new feature
* **fix**: A bug fix
* **docs**: Documentation only changes
* **style**: Code style changes (formatting, missing semi-colons, etc.) with no logic changes
* **refactor**: Code change that neither fixes a bug nor adds a feature
* **perf**: Performance improvements
* **test**: Adding or modifying tests
* **build**: Changes that affect the build system or external dependencies
* **ci**: CI/CD configuration or scripts
* **chore**: Miscellaneous changes (maintenance, tooling, etc.)
* **revert**: Reverts a previous commit

---

### 3. **Scope (optional)**

A **scope** describes the section of the codebase the change affects (in parentheses, right after the type).

Examples:

* `feat(auth): add JWT authentication`
* `fix(api): correct user pagination`

---


✅ **In short**:

* Stick to `<type>(scope): description`.
* Keep it concise, imperative, and consistent.
* Use body for details and footer for breaking changes/issues.

---
