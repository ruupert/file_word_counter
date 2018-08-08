# file word counter

This is an attempt on rewriting same functionality as in [Editorish](https://github.com/ruupert/editorish) but in C and gui in QT5.

In earlier version each file was associated with a FileSummary which had a hashmap of FileWordSummaries which lead to storing the each word into memory in worst case O(n) space where n is the number of files read.

In this rewrite the intention is to store any unique word found in any of the files read just once in a data structure which resembles a radix tree. The above FileWordSummary would instead of a string have a pointer to the tree node where the stored word ends.

