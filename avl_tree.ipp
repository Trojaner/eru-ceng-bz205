#pragma once
#include <cstddef>
#include <iostream>
#include <algorithm>

template <typename T>
void avl_tree<T>::make_empty(avl_node<T>* t) noexcept
{
	if (t == nullptr)
	{
		return;
	}

	make_empty(t->left);
	make_empty(t->right);
	delete t;
}

template <typename T>
avl_node<T>* avl_tree<T>::insert(const T& x, avl_node<T>* t) noexcept
{
	if (t == nullptr)
	{
		t = new avl_node<T>;
		t->data = x;
		t->height = 0;
		t->left = t->right = nullptr;
	}
	else {
		if (compare(x, t->data) < 0)
		{
			t->left = insert(x, t->left);
			if (height(t->left) - height(t->right) == 2)
			{
				if (compare(x, t->left->data) < 0)
					t = single_right_rotate(t);
				else
					t = double_right_rotate(t);
			}
		}
		else if (compare(x, t->data) > 0)
		{
			t->right = insert(x, t->right);
			if (height(t->right) - height(t->left) == 2)
			{
				if (compare(x, t->right->data) > 0)
					t = single_left_rotate(t);
				else
					t = double_left_rotate(t);
			}
		}

		t->height = std::max(t->left == nullptr ? height(t->left) : 0, t->right == nullptr ? height(t->right) : 0) + 1;
	}

	return t;
}

template <typename T>
avl_node<T>* avl_tree<T>::single_right_rotate(avl_node<T>*& t) noexcept
{
	if (t->left != NULL) {
		avl_node<T>* u = t->left;
		t->left = u->right;
		u->right = t;
		t->height = max(height(t->left), height(t->right)) + 1;
		u->height = max(height(u->left), t->height) + 1;
		return u;
	}
	return t;
}

template <typename T>
avl_node<T>* avl_tree<T>::single_left_rotate(avl_node<T>*& t) noexcept
{
	if (t->right != NULL) {
		avl_node<T>* u = t->right;
		t->right = u->left;
		u->left = t;
		t->height = max(height(t->left), height(t->right)) + 1;
		u->height = max(height(t->right), t->height) + 1;
		return u;
	}
	return t;
}

template <typename T>
avl_node<T>* avl_tree<T>::double_left_rotate(avl_node<T>*& t) noexcept
{
	t->right = single_right_rotate(t->right);
	return single_left_rotate(t);
}

template <typename T>
avl_node<T>* avl_tree<T>::double_right_rotate(avl_node<T>*& t) noexcept
{
	t->right = single_left_rotate(t->right);
	return single_right_rotate(t);
}

template <typename T>
avl_node<T>* avl_tree<T>::find_min(avl_node<T>* t) noexcept
{
	if (t == nullptr)
		return nullptr;

	if (t->left == nullptr)
		return t;

	return find_min(t->left);
}

template <typename T>
avl_node<T>* avl_tree<T>::find_max(avl_node<T>* t) noexcept
{
	if (t == nullptr)
		return nullptr;
	if (t->right == nullptr)
		return t;
	return find_max(t->right);
}

template <typename T>
avl_node<T>* avl_tree<T>::remove(const T& x, avl_node<T>* t) noexcept
{
	avl_node<T>* temp;

	// Element not found
	if (t == nullptr)
		return nullptr;

	// Searching for element
	if (compare(x, t->data) < 0)
		t->left = remove(x, t->left);
	else if (compare(x, t->data) > 0)
		t->right = remove(x, t->right);

	// Element found
	// With 2 children
	else if (t->left && t->right)
	{
		temp = find_min(t->right);
		t->data = temp->data;
		t->right = remove(t->data, t->right);
	}
	// With one or zero child
	else
	{
		temp = t;
		if (t->left == nullptr)
			t = t->right;
		else if (t->right == nullptr)
			t = t->left;

		size_--;
		delete temp;
	}
	if (t == nullptr)
		return t;

	t->height = max(height(t->left), height(t->right)) + 1;

	// If node is unbalanced
	// If left node is deleted, right case
	if (height(t->left) - height(t->right) == -2)
	{
		// right right case
		if (height(t->right->right) - height(t->right->left) == 1)
			return single_left_rotate(t);

		// right left case
		return double_left_rotate(t);
	}
	// If right node is deleted, left case
	else if (height(t->right) - height(t->left) == 2)
	{
		// left left case
		if (height(t->left->left) - height(t->left->right) == 1) {
			return single_right_rotate(t);
		}

		// left right case
		return double_right_rotate(t);
	}
	return t;
}

template <typename T>
int avl_tree<T>::height(avl_node<T>* t) noexcept
{
	return (t == nullptr ? -1 : t->height);;
}

template <typename T>
int avl_tree<T>::get_balance(avl_node<T>* t) noexcept
{
	if (t == nullptr)
		return 0;

	return height(t->left) - height(t->right);
}

template <typename T>
void avl_tree<T>::print(avl_node<T>* t) noexcept
{
	if (t == nullptr)
		return;
	print(t->left);
	std::cout << t->data << endl;
	print(t->right);
}

template <typename T>
void avl_tree<T>::insert(const T& item) noexcept
{
	root = insert(item, root);
	size_++;
}

template <typename T>
void avl_tree<T>::remove(const T& item) noexcept
{
	root = remove(item, root);
}

template <typename T>
void avl_tree<T>::inorder_traverse(std::function<void(T)> callback, avl_node<T>* node) noexcept
{
	if (node == nullptr)
		return;

	inorder_traverse(callback, node->left);
	callback(node->data);
	inorder_traverse(callback, node->right);
}

template <typename T>
void avl_tree<T>::inorder_traverse(std::function<void(T)> callback) noexcept
{
	inorder_traverse(callback, root);
}

template <typename T>
void avl_tree<T>::postorder_traverse(std::function<void(T)> callback, avl_node<T>* node) noexcept
{
	if (node == nullptr)
		return;

	postorder_traverse(callback, node->left);
	postorder_traverse(callback, node->right);
	callback(node->data);
}

template <typename T>
void avl_tree<T>::postorder_traverse(std::function<void(T)> callback) noexcept
{
	postorder_traverse(callback, root);
}

template <typename T>
void avl_tree<T>::preorder_traverse(std::function<void(T)> callback, avl_node<T>* node) noexcept
{
	if (node == nullptr)
		return;

	callback(node->data);
	preorder_traverse(callback, node->left);
	preorder_traverse(callback, node->right);
}

template <typename T>
void avl_tree<T>::preorder_traverse(std::function<void(T)> callback) noexcept
{
	preorder_traverse(callback, root);
}

template <typename T>
void avl_tree<T>::print() noexcept
{
	print(root);
}

template <typename T>
int avl_tree<T>::size() const noexcept
{
	return size_;
}
