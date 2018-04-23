class KVNode
{
public:
	int key;
	json value;

	KVNode() {}

	KVNode(int key, json value =NULL)
	{
		this->key = key;
		this->value = value;
	}

	~KVNode() {}

	friend std::ostream& operator<<(std::ostream& stream, const KVNode& nd)
	{
		std::cout << "\nKey: " << nd.key;
		std::cout << "\tValue: " << nd.value;
	}

	// The comparision of this class only cares about "key"

	friend bool operator<(const KVNode& l, const KVNode& r)
	{
		return l.key < r.key;
	}

	friend bool operator>(const KVNode& l, const KVNode& r)
	{
		return r < l;
	}
	friend bool operator>=(const KVNode& l, const KVNode& r)
	{
		return !(l < r);
	}
	friend bool operator<=(const KVNode& l, const KVNode& r)
	{
		return !(l > r);
	}



	friend bool operator==(const KVNode& l, const KVNode& r)
	{
		return l.key == r.key;
	}

	friend bool operator!=(const KVNode& l, const KVNode& r)
	{
		return !(l == r);
	}
};
