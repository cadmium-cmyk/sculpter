1. **Apply theme logic**: Re-implement `ViewUtil::applyTheme(int theme)` in `lib/src/view/util.hpp`/`.cpp`. It maps `0 -> System/Default`, `1 -> Light ("Fusion" + light palette)`, `2 -> Dark ("Fusion" + dark palette)`.
2. **Apply theme in main**: In `app/src/main.cpp`, include `view/util.hpp`, read `window/theme` from `config` after loading it, and call `ViewUtil::applyTheme(theme)`.
3. **UI for Configuration**: Re-implement `ViewUtil::comboBox` in `lib/src/view/util.cpp`/`.hpp`. Then in `lib/src/view/configuration.cpp` under the `Misc` tab, add a `QComboBox` for the Theme ("System", "Light", "Dark"). Connect the changed signal to update the config and call `ViewUtil::applyTheme(theme)`.
4. **Compile and Test**: Compile, ensure `./run-tests` passes.
5. **Complete pre commit steps**: Complete pre-commit steps to ensure proper testing, verification, review, and reflection are done.
6. **Submit**: Once all tests pass and pre-commit steps are complete, I will submit the change with a descriptive commit message.
