import importlib.util, os
p = r"c:\Users\Figby\Documents\git-repos\CS1D-Assignment-4\Assignment 4 - Binary Trees.pdf"
print('exists:', os.path.exists(p))
print('size:', os.path.getsize(p) if os.path.exists(p) else 'missing')
mods = ['pypdf', 'PyPDF2', 'pdfplumber', 'fitz', 'pymupdf']
for m in mods:
    print(m, bool(importlib.util.find_spec(m)))
print('done')
