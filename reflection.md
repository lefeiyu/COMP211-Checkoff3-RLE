# AI Exploration Reflection — Draft

> **Draft for review:** I need to personalize this reflection before submitting it. I also need to replace every bracketed placeholder with my exact information.

I approached run-length encoding by breaking the topic into smaller steps. I first asked for a beginner-level explanation of RLE because I wanted to understand the main idea before looking at code. My initial questions were how the program knows when one run ends, how it keeps track of the number of repeated characters, and how an encoded string can be turned back into the original string without losing information.

I used ChatGPT to help me study the compression and decompression process with small examples. The example `AAAAABBBCC -> 5A3B2C` made the basic rule clear: count consecutive matching characters, write the count, and then write the character. Looking at C code helped me connect that rule to variables and loops. In particular, the nested `while` loops made more sense after I saw that the outer loop moves between runs and the inner loop counts characters inside one run.

One thing that surprised me was that compression can make data larger. For example, `ABCDEFGH` becomes `1A1B1C1D1E1F1G1H`. Since none of the characters repeat consecutively, the encoding adds a count for every character and doubles the length in this simple text format. I also learned that the way the format is designed matters. If digits can appear in the original input, count-character notation can become ambiguous unless the format uses separators, escaping, or a different representation.

If I did this project again, I would decide on the supported input and encoding format earlier. I would also trace a few examples by hand before writing the C program. That would help me separate the algorithm from the syntax and catch special cases sooner.

## Required AI conversation evidence

Replace these placeholders with 2–3 prompts copied exactly from the actual conversation:

1. **Prompt 1:** `[PASTE EXACT PROMPT HERE]`
2. **Prompt 2:** `[PASTE EXACT PROMPT HERE]`
3. **Prompt 3 (optional):** `[PASTE EXACT PROMPT HERE OR DELETE THIS ITEM]`

**Conversation permalink:** `[PASTE THE SHARE/PERMALINK TO THE AI CONVERSATION HERE]`

I should verify that the permalink opens correctly for the intended audience before I submit the assignment.
