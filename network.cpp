#include "network.hpp"

void Network::delta(vector<bool>* in) {
	for(int tick = 0; tick < ticks; tick++) {
		if(verb) {
			char buffer[50];
			sprintf(buffer, "Tick %d", currentTick);
			string tickCounter = string(buffer);
			int left = (LINEWIDTH-tickCounter.length())/2;
			int right = (LINEWIDTH-tickCounter.length())%2 == 0 ? left : left + 1;

			cout << endl << BOXC << "╔" << line("═", left) << TICKC << tickCounter << BOXC << line("═", right) << "╗" << endl;
		}
		
		for(auto c = couples->begin(); c != couples->end(); c++) {
			(*c)->pipe();
			if(verb) {
				coupleOutput->insert(coupleOutput->end(), (*c)->getOutput()->begin(), (*c)->getOutput()->end());
			}
		}

		input->delta(in);
		if(verb) {
			char buffer [50];
			sprintf(buffer, "%p ran delta", input);
			coupleOutput->push_back(string(buffer));
		}
		
		for(auto c = couples->begin(); c != couples->end(); c++) {
			(*c)->deltas();
			if(verb) {
				coupleOutput->insert(coupleOutput->end(), (*c)->getOutput()->begin(), (*c)->getOutput()->end());
			}
		}

		if(verb) {
			for(auto s = coupleOutput->begin(); s != coupleOutput->end(); s++) {
				int right = LINEWIDTH-(*s).length();
				cout << "║" << RESETC << (*s) << line(" ", right) << BOXC << "║" << endl;
			}

			cout << "╚" << line("═", LINEWIDTH) << "╝" << RESETC << endl;
		}

		coupleOutput->clear();
		currentTick++;
	}
}

void Network::verbose() {
	verb = !verb;
	for(auto c = couples->begin(); c != couples->end(); c++) {
		(*c)->verbose();
	}
}

string Network::line(string c, int num) {
	string ret = "";
	for(int i = 0; i < num; i++) {
		ret += c;
	}
	
	return ret;
}
