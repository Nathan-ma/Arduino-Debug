#  Arduino Debuger
## NewMacros: v0.0.1
    - Updating Macros to reduce size of Color Commands and also returning true on print and false on error.

# Rules:
 1. Error(Red) : Critial Error Messages. Reports a bold red error message and also return false.

 2. Warn(Yellow) : Warning Messages. Reports a Yellow warning but dont return anything.

 3. Info(Green) : Informatinal Messages. Reports a Green Message and also returns true.

 3. Notice(Magenta) : Extremely important information, will always remote report if remote report is enabled.

 4. Verbose(Debug) : Debugging Messages. mean to print every single state in the code, returns nothing.