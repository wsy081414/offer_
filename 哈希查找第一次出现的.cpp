
class solution {
  char findStringTwo(std::string& arr) {
  	std::unordered_map<char, int> count;
  	for (int j = 0; j < arr.size(); ++j) {
      ++count[arr[j]];
    }
    
  	for (int i = 0; i < arr.size(); ++i) {
  		if (count[arr[i]] == 2) {
  			return arr[i];
  		}
    }
  		return -1;
  }
}

