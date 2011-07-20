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

#ifndef DOC_H
#define DOC_H
#endif

#define NOTKWON_DOC -1
#define PDF_DOC 1

struct Image {
    int offset;
    int length;
    char *text;
};

struct Text {
    int offset;
    int length;
    char *text;
};

struct Document {
    char *filename;

    char version;
    char info;
    int descriptor;
    int doctype;
    struct Image *image;
    struct Text *text;
};

struct Document getDoc(char []);

int openDoc(struct Document *);
int closeDoc(struct Document *);
int getDocStartLineBack(struct Document *, int);
char *getDocLine(struct Document *, int);
int getDocType(struct Document *);



