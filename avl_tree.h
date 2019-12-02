#pragma once

template<typename T>
class avl_node
{
public:
	avl_node()
	{
		left = nullptr;
		right = nullptr;
		height = 0;
	}

	T data;
	avl_node<T>* left;
	avl_node<T>* right;
	int height;
};

template<typename T>
class avl_tree
{
public:
	virtual ~avl_tree() = default;

	avl_tree()
	{
		root = nullptr;
	}

	void insert(T item);
	void remove(T item);
	void print_inorder();
protected:
	avl_node<T>* root;
	virtual int compare(T a, T b) = 0;
private:
	void make_empty(avl_node<T>* t) noexcept;
	avl_node<T>* insert(T x, avl_node<T>* t);
	avl_node<T>* single_right_rotate(avl_node<T>*& t);
	avl_node<T>* single_left_rotate(avl_node<T>*& t);
	avl_node<T>* double_left_rotate(avl_node<T>*& t);
	avl_node<T>* double_right_rotate(avl_node<T>*& t);
	avl_node<T>* find_min(avl_node<T>* t);
	avl_node<T>* find_max(avl_node<T>* t);
	avl_node<T>* remove(T x, avl_node<T>* t);
	int height(avl_node<T>* t);
	int get_balance(avl_node<T>* t);
	void inorder(avl_node<T>* t);
};

#include "avl_tree.ipp"