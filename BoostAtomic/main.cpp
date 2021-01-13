#include <iostream>
#include <boost/atomic.hpp>

int main()
{

	// 创建atomic对象有两种方法：
	// 1、有参构造函数创建有处置的atomic
	// 2、缺省构造函数创建一个初值不确定的atomic

	boost::atomic<int> a(10);
	assert(a == 10);
	
	boost::atomic<int> l;
	std::cout << l << std::endl;  // 打印垃圾值

	// store()和load()，以原子的方式存取atomic内部的值，不会因并发访问导致数据不一致。

	boost::atomic<bool> b{ false };
	assert(!b.load());

	b.store(true);
	assert(b);

	boost::atomic<int> n(100);

	assert(n.exchange(200) == 100);
	assert(n == 200);

	boost::atomic<long> li(100);
	long v = 101;
	// 比较并交换被封装的值，与v所指定的值是否相等：
	// 相等，则用313替换li中的值 返回true
	// 不相等，则用li的值与v替换。返回false
	if (li.compare_exchange_weak(v, 313)){
		assert(li == 313 && v == 100);
		std::cout << li.load() << " " << v << std::endl;
	}
	else{
		std::cout << "li.compare_exchange_weak error" << std::endl;
		std::cout << li.load() << " " << v << std::endl;

	}

	boost::atomic<long> li2(100);
	long v1 = 101;
	// 比较并交换被封装的值，与v所指定的值是否相等：
	// 相等，则用313替换li中的值 返回true
	// 不相等，则用li的值与v替换。返回true
	if (li2.compare_exchange_weak(v, 313)){
		assert(li2 == 313 && v1 == 101);
		std::cout << li2.load() << " " << v1 << std::endl;
	}
	else{
		std::cout << "li2.compare_exchange_weak error" << std::endl;
		std::cout << li2.load() << " " << v1 << std::endl;

	}
	system("pause");
	return 0;
}