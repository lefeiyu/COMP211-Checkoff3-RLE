# AI Exploration Reflection — Draft

> **Draft for review:** I need to personalize this reflection before submitting it and add the conversation permalink below.

I approached run-length encoding by breaking the topic into smaller steps. I first asked for a beginner-level explanation of RLE because I wanted to understand the main idea before looking at code. My initial questions were how the program knows when one run ends, how it keeps track of the number of repeated characters, and how an encoded string can be turned back into the original string without losing information.

I used ChatGPT to help me study the compression and decompression process with small examples. The example `AAAAABBBCC -> 5A3B2C` made the basic rule clear: count consecutive matching characters, write the count, and then write the character. Looking at C code helped me connect that rule to variables and loops. In particular, the nested `while` loops made more sense after I saw that the outer loop moves between runs and the inner loop counts characters inside one run.

One thing that surprised me was that compression can make data larger. For example, `ABCDEFGH` becomes `1A1B1C1D1E1F1G1H`. Since none of the characters repeat consecutively, the encoding adds a count for every character and doubles the length in this simple text format. I also learned that the way the format is designed matters. If digits can appear in the original input, count-character notation can become ambiguous unless the format uses separators, escaping, or a different representation.

If I did this project again, I would decide on the supported input and encoding format earlier. I would also trace a few examples by hand before writing the C program. That would help me separate the algorithm from the syntax and catch special cases sooner.

## Required AI conversation evidence

### Prompt 1 — Understanding RLE with My Background

> "Can you explain what Run-Length Encoding (RLE) is? I'm currently taking COMP 211, and I've learned some basic concepts in C and computer systems, such as pointers, memory management, the stack and heap, and loops. However, I haven't learned much about data compression. Could you explain RLE from the beginning and connect it to things I already know?"

### Prompt 2 — Understanding the Algorithm in C

> "I understand that RLE counts consecutive repeated characters, but I'm still confused about how a computer actually does this. Since I've learned about strings, pointers, and while loops in COMP 211, can you walk me through a simple C implementation? Please explain what each variable does and how the program changes step by step."

### Prompt 3 — Exploring RLE's Limitations

> "I thought compression was supposed to make data smaller, but I noticed that RLE can actually make some strings longer. Why does that happen? Can you compare an example with many repeated characters to one without repetition, and explain when RLE is useful in real-world applications?"

**Conversation permalink:** `[PASTE THE SHARE/PERMALINK TO THE AI CONVERSATION HERE]`

I should verify that the permalink opens correctly for the intended audience before I submit the assignment.
