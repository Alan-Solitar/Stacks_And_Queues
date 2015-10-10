#ifdef NODE_H

template<typename t>
node<t>::node(t node_data)
{
	data = node_data;
	next = nullptr;
}
template <typename t>
node<t>::node()
{
	
}
#endif