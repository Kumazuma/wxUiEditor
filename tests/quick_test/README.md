This directory is designed to use when you need to quickly test out code generation in one or more languages. As such, the directory itself is in the .gitignore list and only a few files (like this one) are tracked. The only generated files that are tracked are the main files used to launch the specific language app (e.g., py_main.py).

If you are running a Debug build of wxUiEditor with the test.wxui project loaded, two menu items under the Internal menu will let you spawn a shell and run either the python or ruby app in the quick_test/python or quick_test/ruby directories. For this to work, you will need both the language and the wxWidgets language variant installed and in your PATH. (E.g., ruby and wxRuby3).