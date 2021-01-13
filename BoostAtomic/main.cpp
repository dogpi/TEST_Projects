#include <iostream>
#include <boost/atomic.hpp>

int main()
{

	// ����atomic���������ַ�����
	// 1���вι��캯�������д��õ�atomic
	// 2��ȱʡ���캯������һ����ֵ��ȷ����atomic

	boost::atomic<int> a(10);
	assert(a == 10);
	
	boost::atomic<int> l;
	std::cout << l << std::endl;  // ��ӡ����ֵ

	// store()��load()����ԭ�ӵķ�ʽ��ȡatomic�ڲ���ֵ�������򲢷����ʵ������ݲ�һ�¡�

	boost::atomic<bool> b{ false };
	assert(!b.load());

	b.store(true);
	assert(b);

	boost::atomic<int> n(100);

	assert(n.exchange(200) == 100);
	assert(n == 200);

	boost::atomic<long> li(100);
	long v = 101;
	// �Ƚϲ���������װ��ֵ����v��ָ����ֵ�Ƿ���ȣ�
	// ��ȣ�����313�滻li�е�ֵ ����true
	// ����ȣ�����li��ֵ��v�滻������false
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
	// �Ƚϲ���������װ��ֵ����v��ָ����ֵ�Ƿ���ȣ�
	// ��ȣ�����313�滻li�е�ֵ ����true
	// ����ȣ�����li��ֵ��v�滻������true
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