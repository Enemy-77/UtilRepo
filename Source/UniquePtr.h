template<typename T>
class unique_ptr
{
public:
	explicit unique_ptr(T* ptr = nullptr)
		: ptr_(ptr) {
	}

	~unique_ptr()
	{
		delete ptr_;
	}

	template<typename U>
	unique_ptr(unique_ptr<U>&& ptr)
	{
		ptr_ = ptr.release();
	}

	unique_ptr& operator=(unique_ptr rhs)
	{
		unique_ptr(rhs).swap(*this);
		return this;
	}

	T* release()
	{
		T* ptr = ptr_;
		ptr_ = nullptr;
		return ptr;
	}

	void swap(const unique_ptr& ptr)
	{
		using std::swap;
		swap(ptr_, ptr);
	}

	T* get() const { return ptr_; }
	T& operator*() { return *ptr_; }
	T* operator->() { return ptr_; }
	operator bool() const { return ptr_; }

private:
	T* ptr_;
};
