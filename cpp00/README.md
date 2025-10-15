# namespace -> std

````markdown
# 🚫 Why "using namespace std;" is Forbidden in 42 C++ Modules

In 42 Network C++ projects (CPP00 → CPP09), it’s **forbidden** to use  
`using namespace std;`.  
Instead, you must **explicitly prefix** all standard library objects with `std::`.

---

## 🧩 The Difference

### ✅ Using `std::`
```cpp
#include <iostream>

int main() {
    std::cout << "Hello, 42!" << std::endl;
    std::string message = "Welcome to C++";
    return 0;
}
````

Here, every symbol (`cout`, `endl`, `string`, etc.) is **explicitly** taken from the **standard library namespace** (`std`).

✔️ **Clear**
✔️ **Safe**
✔️ **Allowed**

---

### 🚫 Using `using namespace std;`

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, 42!" << endl;
    string message = "Welcome to C++";
    return 0;
}
```

This imports **all names** from the standard library into the **global namespace**, so you no longer need `std::`.

⚠️ **Risky**
⚠️ **Ambiguous**
❌ **Forbidden at 42**

---

## 💥 Why It’s a Problem (Namespace Pollution)

When you write:

```cpp
using namespace std;
```

You pull **hundreds of names** into the global scope.
That can cause **naming conflicts** if your code or another library defines the same name.

### Example:

```cpp
#include <iostream>
using namespace std;

int count = 42;

int main() {
    cout << "Count: " << count << endl;
    return 0;
}
```

Now, if the standard library defines a function called `count()`,
your variable name **conflicts** with it — leading to **compiler errors or unexpected behavior**.

---
