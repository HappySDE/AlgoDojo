#pragma once

namespace SLL {

	struct Node {
		int data;
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

	template<typename Cin>
	Node* buildSllReverse(Cin& cin)
	{
		unsigned N;
		cin >> N;
		if (N == 0)
		{
			return nullptr;
		}

		Node* pHead = nullptr;
		for (unsigned i = 0; i < N; ++i)
		{
			int val;
			cin >> val;
			pHead = new Node{ val, pHead };
		}

		return pHead;
	}

	template<typename Cout>
	void printSll(Cout& out, const Node* pHead)
	{
		while (pHead)
		{
			out << pHead->data;
			if (pHead->next)
			{
				out << ' ';
			}
			pHead = pHead->next;
		}
		out << '\n';
	}

	inline
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