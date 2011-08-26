import os

def getLineBack(nline):

    f = file("test.pdf", "rb")
    i = 1
    line = []
    n = ""
    nline_ = 0

    while True:

        f.seek(-i, os.SEEK_END)
        n = f.read(1)

        if n == '\n':
            if nline_ == nline:
                break
            line = []
            nline_ += 1
        else:
            line.append(n)

        i += 1

    line.reverse()
    return repr("".join(line))


def getLineForward(nline):

    f = file("test.pdf", "rb")
    i = 0
    line = []
    n = ""
    nline_ = 0


    while True:

        f.seek(i)
        n = f.read(1)

        if n == '\n':
            if nline_ == nline:
                break
            line = []
            nline_ += 1
        else:
            line.append(n)

        i += 1

    return repr("".join(line))


if __name__ == '__main__':

    print 0, getLineBack(0)
    print 1, getLineBack(1)
    print 2, getLineBack(2)
    print 3, getLineBack(3)
    print
    print 0, getLineForward(0)
    print 1, getLineForward(1)
    print 2, getLineForward(2)
    print 3, getLineForward(3)
