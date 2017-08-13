#pragma once

namespace SLL {

	struct Node {
		int value;
		Node* next;
	};

	template<typename Cin>
	Node* buildSll(Cin& cin)
	{
		unsigned N;
		cin >> N;
		if (N == 0)
		{
			return nullptr;
		}

		int val;
		cin >> val;
		Node* pHead = new Node{ val, nullptr };
		Node* pCurr = pHead;
		for (unsigned i = 1; i < N; ++i)
		{
			cin >> val;
			Node* pNew = new Node{ val, nullptr };
			pCurr->next = pNew;
			pCurr = pCurr->next;
		}

		return pHead;
	}

	template<typename Cout>
	void printSll(Cout& out, const Node* pHead)
	{
		while (pHead)
		{
			out << pHead->value;
			if (pHead->next)
			{
				out << ' ';
			}
			pHead = pHead->next;
		}
		out << '\n';
	}

	void destroySll(Node* pHead)
	{
		while (pHead)
		{
			Node* pNext = pHead->next;
			delete pHead;
			pHead = pNext;
		}
	}

} // namespace SLL