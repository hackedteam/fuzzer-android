import sys

f = open(sys.argv[1], "r")
f2 = open(sys.argv[2], "w")


for c,i in enumerate(f.readlines()):
    if c == 1:
        f2.write("<FUZZED_SYSCALLS>" + i.replace("\r\n", ""))
    else:
        f2.write(i.replace("\r\n", ""))

f2.write("</FUZZED_SYSCALLS>");
