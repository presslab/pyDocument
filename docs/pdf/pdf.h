/*
Copyright (c) 2009 Prima Tech Informatica Ltda.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <document.h>

#ifndef PDF_H
#define PDF_H
#endif

enum XRefType {
  xrefEntryFree,
  xrefEntryUncompressed,
  xrefEntryCompressed
};

struct XRefEntry {
  int offset;
  int gen;
  enum XRefType type;
};

int getXRefSize(struct Document *doc);

int getInfo(struct Document *doc);

int getImages(struct Document *doc, int page);

int getText(struct Document *doc, int page);

int getTextPos(struct Document *doc, int page);

int getNumPages(struct Document *doc);

int getVersion(struct Document *doc);

