#IOL.cn

Chinese translation for problems of the International Linguistics Olympiad (IOL)

##文件结构

每一届 IOL 赛题由三个文件组成，以第十届 IOL 的英语版为例，``IOL10.tex`` 为数据文件，``dxIOL10EN.tex`` 为英语相关内容的文件，``IOL10en.tex`` 引用前两者，为主文件。

``dxIOL10EN.tex`` 由一连串的 ``\def`` 组成：

```LaTeX
\def \thistext{English text}
\def \nthIOL #1{#1 International Olympiad in Linguistics}
\def \thisth{Tenth}
\def \thisland{Slovenia}
\def \thistown{Ljubljana}
\def \Julyname{July}
\def \Auguname{August}
\def \olydates #1#2#3#4#5{#1 #2 – #3 #4 #5}
\def \leafword #1{Sheet \##1}
\def \probword #1{Problem \##1}
\def \probsing #1{#1 Problem}
\def \probplur #1{#1 Problems}
\def \respsing #1{#1 Answers}
\def \solusing #1{#1 Solution}
\def \soluplur #1{#1 Solutions}
```

``IOL10.tex`` 则会引用 ``dxIOL10XX.tex`` 中的定义，以此实现国际化。

``IOL10en.tex`` 是主文件，内容如下：

```LaTeX
\documentclass[11pt]{article}
\usepackage{a4wide}
\usepackage[T3,T1]{fontenc}
\usepackage[noenc]{tipa}
\usepackage{tipx}
\usepackage[notipa]{ucs}
\usepackage[utf8x]{inputenc}
\usepackage[english,UKenglish]{babel}
\input{dxIOL10en}
\newcommand \dmy [3]{#1/#2/#3} %%% UK, IE, OZ
\newcommand \dialog {dialogue}
\newcommand \axe {axe}
\newcommand \ous {ou$_{\textrm{\small sg}}$}
\newcommand \oup {ou$_{\textrm{\small pl}}$}
\input{IOL10}
```

理论上，翻译工作只需要在 ``dxIOLnCN.tex`` 中进行，这也是组委会如此编排文件的原因。[^1]

##目前状态

年份 | 是否完成 | 翻译 | 排版
--- | --- | --- | ---
2003 | 否 | N/A | N/A
2004 | 否 | N/A | N/A
2005 | 否 | N/A | N/A
2006 | 否 | N/A | N/A
2007 | 否 | N/A | N/A
2008 | 否 | N/A | N/A
2009 | 是 | 曹起曈 | 刘闽晟
2010 | 是 | 曹起曈 | 刘闽晟
2011 | 是 | 曹起曈，刘闽晟 | 刘闽晟
2012 | 是 | 曹起曈，戴谊凡，刘闽晟 | 刘闽晟
2013 | 否 | N/A | N/A

需要注意的是，所有的 ``XeLaTeX`` 文档只在 ``OS X`` 下通过测试。

##有关技术细节

IOL 试题原本使用 ``LaTeX``。考虑到 UTF-8 编码的支持和方便的字体管理，``IOL.cn`` 使用 ``XeLaTeX``，及 ``XeCJK`` 和 ``fontspec`` 宏包。

目前完成翻译的两届试题中，汉字的字体均使用 ``OS X`` 预装的字体。我们正在尝试联系常州华文获得许可。

IOL 试题的英文字体用的是 ``Computer Modern``。为配合 ``XeLaTeX``，我们已经决定改为其 Unicode 版本 ``Computer Modern Unicode``。有关字体可以在 ``fonts`` 文件夹找到。

``utils/RemoveSpace`` 是一个自动删除空格的 ``C++`` 程序，使用 ``WTFPL`` 协议发布。它用于处理那些 ``XeCJK`` 无法正常处理的空格，可参考源文件注释。

##感谢

在此感谢 [Ivan A Derzhanski](http://www.math.bas.bg/~iad/) 先生对我们的翻译项目的支持。感谢他为我们提供 IOL 题目的源文件并给我们的翻译提供建议。

##引用

[^1]:Derzhanski, Ivan. "Multilingual Editing of Linguistic Problems." ACL 2013 (2013): 27.