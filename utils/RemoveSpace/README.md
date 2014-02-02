#README.md

RemoveSpace.cpp is a C++ program used to automatically remove unnecssary spaces in IOLxx.tex files. Its principle is quite simple: if we have the following pattern, the spaces inside should be eliminated:

```LaTeX
\ChineseLabel{xxx} \ChineseLabel => \ChineseLabel{xxx}\ChineseLabel
\ChineseLabel\ \ChineseLabel => \ChineseLabel\ChineseLabel
```

To compile it, you need a C++ 11 compiler. It is tested on OS X 10.9 Mavericks with Clang 3.3 svn (Apple LLVM version 5.0).

This mini program is licensed under WTFPL, the content of which is as following:

```
DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
  TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

 0. You just DO WHAT THE FUCK YOU WANT TO.
 ```