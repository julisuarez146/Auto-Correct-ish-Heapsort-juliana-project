# Auto-Correct-ish-Heapsort-juliana-project
Heap-Powered Auto-Suggest Build a live name-search widget using a priority heap and a custom heuristic — inside a Malena application.

**The Heap class** is only responsible for the heap data structure. It stores items in a vector, uses siftUp after insertion, and uses siftDown after extraction. This is a real heap, not a sorted list. The heap does not know anything about names, files, or the user interface.

**The NameHeuristic class** is responsible for scoring. It receives the user’s query and a candidate name, then returns a numeric score. My heuristic is case-insensitive. It gives points for exact matches, prefix matches, partial matches, consecutive matching letters, and it slightly prefers shorter names when scores are similar. This goes beyond simple prefix matching.

**The SuggestEngine class** is the brain of the program. It receives the query from the UI, asks the heuristic to score each name, inserts the valid suggestions into the heap, and extracts the top ten results.

**The FileLoader class** only reads the names.txt file and returns the names in a vector. This keeps file reading separate from the rest of the logic.

**Build Instructions**

From the project directory:

cmake -B build
cmake --build build

**Run Instructions**

After building:

./build/MalenaTutorial

Author
Juliana Suarez
