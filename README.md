# IOL.cn

Chinese translation for International Linguistics Olympiad (IOL) 2003-2013.

For IOL 2008-2013, we are using XeLaTeX. Only being compiled under OS X.

## Current Status

Year | Status  | Translating | Typesetting
---- | ------- | ----------- | -----------
2003 | In Progress | Run Chen |    N/A
2004 | On Hold |     N/A     |     N/A
2005 | On Hold |     N/A     |     N/A
2006 | On Hold |     N/A     |     N/A
2007 | On Hold |     N/A     |     N/A
2008 | Done | Minsheng Liu, Han Liu | Minsheng Liu
2009 | Done | Qitong Cao | Minsheng Liu
2010 | Done | Qitong Cao | Minsheng Liu
2011 | Done | Qitong Cao, Minsheng Liu | Minsheng Liu
2012 | Done | Qitong Cao, Ivan Derzhanski, Minsheng Liu | Minsheng Liu
2013 | Done | Qitong Cao, Minsheng Liu | Minsheng Liu

## Want to Help?

Do __NOT__ fork and pull request. Instead, start an issue and we will see what
you can help.

IOL 2003 - 2007 uses Microsoft Word. We currently have no idea of how to
collaborate.

## Structure

```
/fonts: Fonts used by this project.
/md: Markdown version of IOL problems. This subproject is pause.
/PDFs: Compiled result.

/src/IOL.cn: XeLaTeX source code of Chinese version.
/src/IOL.en: Original LaTeX source code of English version.
/src/MLT: Port of English version to XeLaTeX.

/utils: Utilities used by this project like removing all spaces between Chinese
characters.
```

## Compilation Process

There are two executable scripts for each platform. One is for editing and will
produce everything in one single document. The other one is for release and
will produce four documents. Since we control output through LaTeX package
``pagesel``, the latter works similar to the former.

1. ``RemoveSpace`` will be called and produce IOLxx.nospace.tex.
2. ``font-selector.tex`` will be copied from ``/src/IOL.cn``.
3. Script will call xelatex to compile ``IOLxxcn.tex``.
4. ``IOLxxcn.tex`` import ``font-selector.tex`` which sets up correct fonts.
5. ``IOLxxcn.tex`` import ``dxIOLxxCN.tex`` containing all Solverse-related
    texts.
6. ``IOLxxcn.tex`` import ``IOLxx.nospace.tex`` containing the document
    template.

Not hard to understand, right?



## Fonts

English font family used in this project is Computer Modern, default font
family for *TeX*. Since XeLaTeX has native support for modern font files and
UTF-8, we used [Computer Modern Unicode](http://cm-unicode.sourceforge.net)
version. We have included those font files inside the project and use relative
path to locate them.

Chinese fonts are a little more complicated. We currently use fonts shipped
within OS X. We will find well-designed fonts which could be included inside
this project too.

We use a font-selecotr file like this:

```LaTeX
% check out full version in src/IOL.cn/font-selector.tex
\usepackage{fontspec}
\usepackage{xeCJK}
\usepackage{ifplatform}

\setmainfont[
  Path = ../../../fonts/CMUnicode/,
  Extension = .ttf,
  BoldFont = *-Bold,
  ItalicFont = *-Italic,
  BoldItalicFont = *-BoldItalic,
  SlantedFont = *-RomanSlanted,
  UprightFont = *-Roman
]{CMUSerif}
\setsansfont[...]{CMUSansSerif}

\ifmacosx
\setCJKmainfont[
  BoldFont = Songti SC Bold,
  ItalicFont = Kaiti SC Regular,
  BoldItalicFont = Kaiti SC Bold,
  SlantedFont = STFangsong
]{Songti SC Regular}
\setCJKsansfont[...]{Heiti SC Light}
\else
\fi

% Use Computer Modern Serif for those characters.
\normalspacedchars{•‘’“”1234567890-—–/̄́`ˇ}
```

Sans serif typeface has ocurred only once so far. Normally we do not need it for
 Chinese fonts selection.

If you are using Windows, you could add the following code:

```
\ifmacosx
...
\else
\ifwindows
% font selection code goes here...
\else
\fi
\fi
```

## Acknowledgements

Thanks [Ivan A Derzhanski](http://www.math.bas.bg/~iad/) for his support to our
project and provision of IOL source codes.
