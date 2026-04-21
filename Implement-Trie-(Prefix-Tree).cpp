1class Trie {
2public:
3    static const int k = 26;
4    struct Node {
5        int go[k];
6        int freq;
7        int end = 0;
8        Node() {
9            fill(go, go + k, -1);
10            freq = 0;
11        }
12    };
13
14    vector<Node> aut;
15    Trie() {
16        aut.resize(1);
17    }
18
19    void insert(string word) {
20        int u = 0; // cur node
21        for (char ch : word) {
22            int c = ch - 'a';
23            if (aut[u].go[c] == -1) {
24                aut[u].go[c] = (int)aut.size();
25                aut.emplace_back();
26            }
27            u = aut[u].go[c];
28            aut[u].freq++;
29        }
30        aut[u].end++;
31    }
32
33    bool search(string word) {
34        int u = 0;
35        for (char ch : word) {
36            int c = ch - 'a';
37            if (aut[u].go[c] == -1)
38                return false;
39            u = aut[u].go[c];
40        }
41        return aut[u].end > 0;
42    }
43
44    bool startsWith(string prefix) {
45        int u = 0;
46        for (char ch : prefix) {
47            int c = ch - 'a';
48            if (aut[u].go[c] == -1)
49                return false;
50            u = aut[u].go[c];
51        }
52        return true;
53    }
54};
55
56/**
57 * Your Trie object will be instantiated and called as such:
58 * Trie* obj = new Trie();
59 * obj->insert(word);
60 * bool param_2 = obj->search(word);
61 * bool param_3 = obj->startsWith(prefix);
62 */