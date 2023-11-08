template<typename T>

typename T::iterator easyfind(T& container, int value) {
	typename T::iterator found;

	found = std::find(container.begin(), container.end(), value);
	if (found != container.end()) {
		std::cout << "Value found: " << *found << "\n";
		return (found);
	} else {
		throw std::runtime_error("Value not found");
	}
}