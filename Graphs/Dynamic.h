#pragma once
#include <iostream>

using namespace std;

class Dynamic {

public:

	void exe() {

		cout << "n = "; cin >> n;
		readNodes();
		writeNode();
	}

private:

	struct Edge {

		int val;
		Edge *next;
	};

	struct Node {

		int id;
		Edge *f;
		Node *next;
	};

	Node *f;
	int n;

	void readNodes() {

		Node *l;
		f = new Node;

		f->id = 1;
		f->next = 0;
		l = f;
		cout << "Node 1 links to?\n";
		readEdge(f);

		for(int i = 1; i < n; i++) {
		
			cout << "Node " << i + 1;
			Node *p = new Node;
			p->id = i + 1;
			p->next = 0;
			l->next = p;
			l = p;

			cout << " links to?\n";
			readEdge(p);
		}
	}

	void readEdge(Node *q){
	
		int x;
		Edge *f = q->f = new Edge;
		Edge *l;
		
		cout << "Number of linked nodes is?\n"; cin >> x;
		cout << "First linked node is?\n"; cin >> f->val;
		f->next = 0;
		l = f;

		for (int i = 1; i < x; i++) {

			Edge *p = new Edge;
			cout << "Linked node " << i + 1 << " is?\n"; cin >> p->val;
			p->next = 0;
			l->next = p;
			l = p;
		}
	}

	void writeEdge(Node *q){
	
		for (Edge *p = q->f; p; p = p->next)
			cout << p->val << ' ';
	
		cout << endl;
	}

	void writeNode() {

		for (Node *p = f; p; p = p->next) {

			cout << "Node " << p->id << " links to:\n";
			writeEdge(p);

		}
	}

};