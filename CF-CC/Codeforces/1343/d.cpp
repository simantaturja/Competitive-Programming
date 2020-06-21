/*
  Author : Simanta Deb Turja
  Email: simantaturja@gmail.com
  Website: https://simantaturja.github.io
*/
#include <bits/stdc++.h>
using namespace std;


template <class T> class Vector {
  public:
  int *arr;
  int len = 0;
  Vector() {
    arr = (int*)malloc(1 * sizeof(int));
    len = 0;
  }
  Vector(int size) {
    arr = (T*)malloc(size * sizeof(int));
    len = size;
  }
  void push_back(int value) {
      ++len;
      arr = (T*)realloc(arr, len * sizeof(int));
      arr[len - 1] = value;
  }
  void at(int index) {
      
  }
  void pop_back() {
      
  }
  int size() {
      return len;
  }
  void print() {
      for (int i = 0; i < len; ++i) {
          cout << arr[i] << ' ';
      }
      cout << endl;
  }
};

template <class T> class QueueNode {
    public:
    T value;
    QueueNode *next;
    QueueNode(T value) {
        this->value = value;
        this->next = NULL;
    }
};

template <class T> class Queue {
    public:
    int len = 0;
    QueueNode <T> *head = NULL;
    QueueNode <T> *tail = NULL;
    void push(int value) {                  // O(1)
        QueueNode <T> *node = new QueueNode<T>(value);
        ++len;
        if (head == NULL) {
            head = node;
            head->next = NULL;
            tail = head;
            tail->next = NULL;
            return;
        }
        QueueNode <T> *temp = tail;
        tail = node;
        tail->next = NULL;
        temp->next = tail;
        
    }
    int size() {                // O(1)
        return len;
    }
    T front() {               // O(1)
        return head->value;
    }
    void pop() {                // O(1)
        QueueNode <T> *temp = head;
        delete(head);
        head = temp->next;
        len--;
    }
    
};
const int N = (int)1e5 + 10;
vector <int> adj[N + 7];
int src, height[N + 7], visited[N + 7];

int bfs() {
  Queue <int> q;
  q.push(src);
  height[src] = 1;
  visited[src] = 1;
  int mx = 0;
  while (q.size() != 0) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < (int)adj[u].size(); ++i) {
      int v = adj[u][i];
      if (visited[v] == 0) {
        q.push(v);
        height[v] = height[u] + 1;
        mx = max(height[v], mx);
        visited[v] = 1;
      }
    }
  }
  return mx;
}
void solve() {
    Vector <int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(2);
    v.print();
}
int main() {
  solve();
  return 0;
  int n;
  cin >> n;
  for ( int i = 0; i < n; ++i ) {
    int p;
    cin >> p;
    if (p == -1) {
      src = i;
      continue;
    }

    adj[p].push_back(i);
  }
  cout << bfs() << endl;
  return 0;
}