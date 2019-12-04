#pragma once
#include <functional>

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
	virtual ~avl_tree() noexcept = default;

	avl_tree()
	{
		root = nullptr;
		size_ = 0;
	}

	void insert(const T& item) noexcept;
	void remove(const T& item) noexcept;
	void print() noexcept;
	int size() const noexcept;

	void inorder_traverse(std::function<void(T)> callback) noexcept;
	void postorder_traverse(std::function<void(T)> callback) noexcept;
	void preorder_traverse(std::function<void(T)> callback) noexcept;
protected:
	avl_node<T>* root;
	virtual int compare(const T& a, const T& b) noexcept = 0;
private:
	void make_empty(avl_node<T>* t) noexcept;
	avl_node<T>* insert(const T& x, avl_node<T>* t) noexcept;
	avl_node<T>* single_right_rotate(avl_node<T>*& t) noexcept;
	avl_node<T>* single_left_rotate(avl_node<T>*& t) noexcept;
	avl_node<T>* double_left_rotate(avl_node<T>*& t) noexcept;
	avl_node<T>* double_right_rotate(avl_node<T>*& t) noexcept;
	avl_node<T>* find_min(avl_node<T>* t) noexcept;
	avl_node<T>* find_max(avl_node<T>* t) noexcept;
	avl_node<T>* remove(const T& x, avl_node<T>* t) noexcept;
	int height(avl_node<T>* t) noexcept;
	int get_balance(avl_node<T>* t) noexcept;
	void print(avl_node<T>* t) noexcept;
	void inorder_traverse(std::function<void(T)> callback, avl_node<T>* node) noexcept;
	void postorder_traverse(std::function<void(T)> callback, avl_node<T>* node) noexcept;
	void preorder_traverse(std::function<void(T)> callback, avl_node<T>* node) noexcept;
	int size_;
};

#include "avl_tree.ipp"