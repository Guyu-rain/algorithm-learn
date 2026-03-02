
// 前缀树(Trie Tree)的主要优点：
// 1. 节约存储空间（前缀相同的只存 1 次）
// 2. 方便处理前缀操作，有关前缀的操作时间复杂度都是 O(L)，L 是前缀字符串长度
// 3. 可以使用通配符
// 4. 可以按照字典顺序遍历键，这个 TreeMap 也能做到，但 HashMap 做不到

// Trie 树节点示例： 
// template<typename V>
// struct TrieNode {
//     V val = NULL;
//     TrieNode<V>* children[256] = {NULL};
// };
// 如果 children['a'] != NULL，说明该节点有值

// Trie树 用`树枝`存储字符串（键），用`节点`存储字符串（键）对应的数据（值）。

