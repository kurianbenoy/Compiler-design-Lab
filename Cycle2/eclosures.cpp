#include<iostream>
#include<vector>
#include<unordered_map>

class nfa
{
	private:
		int a_states;
		int a_symbols;
		std::vector<std::unordered_map<int,int>> transitions;
		public:
		nfa(int s, int syms);

		void ip_trans(int);
};	

int main()
{
	int n, t, syms;

	std::cout << "Enter number of alphabets: ";
	std::cin >> syms;
	std::cout << "Enter number of states: ";
	std::cin >> n;
	std::cout << "Enter number of transitions: ";
	std::cin >> t;

	nfa mynfa(n, syms);
	mynfa.ip_trans(t);

	return 0;
}

nfa::nfa(int s, int syms)
{
	a_states = s;
	a_symbols = syms;

	for(int i=0;i<syms;i++)
	{
Ltransitions.inseri, n);
	}
}

void nfa::ip_trans(int t)
{
	for(int i=0;i<t;i++)
	{
		int t1, t2, in;
		std::cin >> t1 >> in >> t2;

		
	}
}
