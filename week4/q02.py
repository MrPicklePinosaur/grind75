class TrieNode:

    def __init__(self, value, filled = False):
        self.filled = filled
        self.value = value
        self.children = [None for i in range(26)]

    def get_node(self, c: str):
        c = ord(c) - ord('a')
        if self.children[c] == None:
            self.children[c] = TrieNode(c)
        return self.children[c]

    def has_node(self, c: str) -> bool:
        c = ord(c) - ord('a')
        return self.children[c] != None

class Trie:

    def __init__(self):
        self.root = TrieNode(None) # special beginning of string character
        
    def insert(self, word: str) -> None:
        self._insert(word, self.root)

    def _insert(self, word: str, node: TrieNode) -> None:
        #print("insert ", word)
        # insert
        if len(word) == 0:
            node.filled = True
        else:
            next_char = word[0]
            next_node = node.get_node(next_char)
            self._insert(word[1:], next_node)

    def search(self, word: str) -> bool:
        return self._search(word, self.root)

    def _search(self, word: str, node: TrieNode) -> bool:
        if len(word) == 0:
            return node.filled
        else:
            next_char = word[0]
            if not node.has_node(next_char):
                return False
            next_node = node.get_node(next_char) 
            return self._search(word[1:], next_node)

    # TODO pretty much duplicate of start(), technically could abstract a bit
    def startsWith(self, prefix: str) -> bool:
        return self._startsWith(prefix, self.root)

    def _startsWith(self, prefix: str, node: TrieNode) -> bool:
        if len(prefix) == 0:
            return True
        else:
            next_char = prefix[0]
            if not node.has_node(next_char):
                return False
            next_node = node.get_node(next_char) 
            return self._startsWith(prefix[1:], next_node)
        
# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
