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

理论上，翻译工作只需要在 ``dxIOLnCN.tex`` 中进行，这也是组委会如此编排文件的原因。但实际上，由于很多中文特色的原因（比如需要将所有的句点改成句号），我们也需要对 ``IOLn.tex`` 文件进行修改。

##目前状态

已近完成的有第十届 IOL，即 IOL 2012。第九届 IOL，即 IOL 2011 的个人赛赛题及解答的翻译工作已完成，但团体赛方面进展缓慢。上述两届赛题的翻译尚未进行仔细的核查。

此外，由于这两届赛题的翻译的主体编辑工作均由 [刘闽晟](https://github.com/notcome) 完成，其他人负责提供建议，所以源代码目前只保证能在 OS X 平台上编译通过。

##有关技术细节

IOL 试题原本使用 ``LaTeX``。考虑到 UTF-8 编码的支持和方便的字体管理，``IOL.cn`` 使用 ``XeLaTeX``。

目前完成翻译的两届试题中，汉字的字体均使用 ``OS X`` 预装的字体，我们将考虑上传没有版权问题的、通用的汉字字体至项目仓库。

IOL 试题的英文字体用的是 ``Computer Modern``。出于一些已经被遗忘的原因（似乎跟国际音标输入有关），我们已经决定改为其 Unicode 版本 ``Computer Modern Unicode``。有关字体可以在 ``fonts`` 文件夹找到。

因为一些已经被遗忘的原因，``IOL10.tex`` 和 ``IOL9.tex`` 在翻译版本中被暴力修改，所有汉字间的空格被手动除去，所有半角标点符号被手工替换。最近 [刘闽晟](https://github.com/notcome) 实现了一个自动替换半角标点符号的宏，但目前还没有经过仔细测试，尚未合并至 ``IOL.cn`` 中。

##感谢

在此感谢 [Ivan A Derzhanski](http://www.math.bas.bg/~iad/) 先生对我们的翻译项目的支持。感谢他为我们提供 IOL 题目的源文件并给我们的翻译提供建议。