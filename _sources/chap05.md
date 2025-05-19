# Chapter 5: An Example of C++ in HEP

While the prevalence of Python within HEP may give you the impression that not much other than this programming language is used, closer inspection would prove otherwise. Many of the libraries that you use in Python actually run on C++ for either historical reasons (they were originally written in C++ and then ported to Python), or for performance (Python is much slower than C++). A famous Python library which uses C++ that is popular even outside the field of HEP are NumPy arrays. In HEP, the ROOT framework is a fundamental component in out analysis toolkit. This software was originally written in C++ and it wasn't until relatively recently libraries such as Uproot have emerged which do not depend on ROOT, but can interfase with root files. 

You might have used PyROOT and RDataFrames in Python. If you have, you have actually been running C++ code. In fact, the syntax used for PyROOT and RDataFrames closely resembles that used with ROOT in C++. For instance, the following are two examples of the same code, one written in C++ and the other in Python. Its not hard to see the resemblence.

```{literalinclude} ../root_code/MakeHistogram.cpp
:language: cpp
:lineno-match:
```

```{literalinclude} ../root_code/MakeHistogram.py
:language: python
:lineno-match:
```

```{admonition} Exercise 5.1
Modify the `MakeHist_JetPt` C++ function by making the line color blue, by having the histogram be filled with the color red, and by setting the y axis scale as logarithmic.
```

Additionally, if you have ever used the ROOT CLI, it should not suprise you to know that you were actually writting C++ code. For instance, if you wanted to access the `Events` TTree of your root data file, you would do something like the following:

```{code}
TFile *f = TFile::Open("./data.root")
TTree *tree;
f->GetObject("Events", tree);
```

While some of what is seen here was not covered in this material, the code we would us to access the data is unmistakably C++.