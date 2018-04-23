template <typename K, typename V>
class KVNode
{
public:
	K key;
	V value;

	KVNode() {}
	~KVNode() {}

	friend bool operator<(const KVNode& l, const KVNode& r)
	{
		return std::tie(l.key, l.value) < std::tie(l.key, l.value);
	}

	friend bool operator==(const KVNode& l, const KVNode& r)
	{
		return std::tie(l.key, l.value) == std::tie(l.key, l.value);
	}

	friend bool operator>(const KVNode& l, const KVNode& r) { return r < l; }
	friend bool operator>=(const KVNode& l, const KVNode& r) { return !(l > r); }
	friend bool operator<=(const KVNode& l, const KVNode& r) { return !(l < r); }
	friend bool operator!==(const KVNode& l, const KVNode& r) { return !(l == r); }
};
