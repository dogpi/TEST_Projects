#include <iostream>

typedef enum MANTYPETag
{
	kFatMan,
	kThinMan,
	kNormal
}MANTYPE;

class Man 
{
public:
	void SetHead(MANTYPE type) {
		m_HeadType = type;
	}
	void SetBody(MANTYPE type) {
		m_BodyType = type;
	}
	void SetLeftHand(MANTYPE type) {
		m_LeftHandType = type;
	}
	void SetRightHand(MANTYPE type) {
		m_RightHandType = type;
	}
	void SetLeftFoot(MANTYPE type) {
		m_LeftFootType = type;
	}
	void SetRightFoot(MANTYPE type) {
		m_RightFootType = type;
	}
	void ShowMan() {
		switch (m_HeadType)
		{
		case kFatMan:
			std::cout << "我有：胖的头";
			break;
		case kThinMan:
			std::cout << "我有：瘦的头";
			break;
		case kNormal:
			std::cout << "我有：不胖不瘦的头";
			break;
		default:
			break;
		}
		switch (m_BodyType)
		{
		case kFatMan:
			std::cout << "、胖的身体";
			break;
		case kThinMan:
			std::cout << "、瘦的身体";
			break;
		case kNormal:
			std::cout << "、不胖不瘦的身体";
			break;
		default:
			break;
		}
		switch (m_LeftHandType)
		{
		case kFatMan:
			std::cout << "、胖的左手";
			break;
		case kThinMan:
			std::cout << "、瘦的左手";
			break;
		case kNormal:
			std::cout << "、不胖不瘦的左手";
			break;
		default:
			break;
		}
		switch (m_RightHandType)
		{
		case kFatMan:
			std::cout << "、胖的右手";
			break;
		case kThinMan:
			std::cout << "、瘦的右手";
			break;
		case kNormal:
			std::cout << "、不胖不瘦的右手";
			break;
		default:
			break;
		}
		switch (m_LeftFootType)
		{
		case kFatMan:
			std::cout << "、胖的左脚";
			break;
		case kThinMan:
			std::cout << "、瘦的左脚";
			break;
		case kNormal:
			std::cout << "、不胖不瘦的左脚";
			break;
		default:
			break;
		}
		switch (m_RightFootType)
		{
		case kFatMan:
			std::cout << "、胖的右脚。"<<std::endl;
			break;
		case kThinMan:
			std::cout << "、瘦的右脚。" << std::endl;
			break;
		case kNormal:
			std::cout << "、不胖不瘦的右脚。" << std::endl;
			break;
		default:
			break;
		}
	}
private:
	MANTYPE m_HeadType;
	MANTYPE m_BodyType;
	MANTYPE m_LeftHandType;
	MANTYPE m_RightHandType;
	MANTYPE m_LeftFootType;
	MANTYPE m_RightFootType;

};

class Builder
{
public :
	virtual void BuildHead() {}
	virtual void BuildBody() {}
	virtual void BuildLeftHand() {}
	virtual void BuildRightHand() {}
	virtual void BuildLeftFoot() {}
	virtual void BuildRightFoot() {}

	virtual Man* GetMan() { return NULL; }
};


// 也可以把构造不同Man的方法放到同一个构造器中，根据参数选择构建具体对象的过程。
// 构造胖子的通用方法
class FatManBuilder :public Builder
{
public:
	FatManBuilder() { m_FatMan = new Man(); }
	void BuildHead() { m_FatMan->SetHead(kFatMan); }
	void BuildBody() { m_FatMan->SetBody(kFatMan); }
	void BuildLeftHand() { m_FatMan->SetLeftHand(kFatMan); }
	void BuildRightHand() { m_FatMan->SetRightHand(kFatMan); }
	void BuildLeftFoot() { m_FatMan->SetLeftFoot(kFatMan); }
	void BuildRightFoot() { m_FatMan->SetRightFoot(kFatMan); }
	Man *GetMan() { return m_FatMan; }
private:
	Man *m_FatMan;
};

// 构造瘦子的通用方法
class ThinManBuilder :public Builder
{
public:
	ThinManBuilder() { m_ThinMan = new Man(); }
	void BuildHead() { m_ThinMan->SetHead(kFatMan); }
	void BuildBody() { m_ThinMan->SetBody(kFatMan); }
	void BuildLeftHand() { m_ThinMan->SetLeftHand(kFatMan); }
	void BuildRightHand() { m_ThinMan->SetRightHand(kFatMan); }
	void BuildLeftFoot() { m_ThinMan->SetLeftFoot(kFatMan); }
	void BuildRightFoot() { m_ThinMan->SetRightFoot(kFatMan); }
	Man *GetMan() { return m_ThinMan; }
private:
	Man *m_ThinMan;
};

// 构造大头的通用方法
class BigHeadManBuilder :public Builder
{
public:
	BigHeadManBuilder() { m_BigHeadMan = new Man(); }
	void BuildHead() { m_BigHeadMan->SetHead(kFatMan); }
	void BuildBody() { m_BigHeadMan->SetBody(kThinMan); }
	void BuildLeftHand() { m_BigHeadMan->SetLeftHand(kThinMan); }
	void BuildRightHand() { m_BigHeadMan->SetRightHand(kThinMan); }
	void BuildLeftFoot() { m_BigHeadMan->SetLeftFoot(kThinMan); }
	void BuildRightFoot() { m_BigHeadMan->SetRightFoot(kThinMan); }
	Man *GetMan() { return m_BigHeadMan; }
private:
	Man *m_BigHeadMan;
};

// 构造小头的通用方法
class SmallManBuilder :public Builder
{
public:
	SmallManBuilder() { m_SmallHeadMan = new Man(); }
	void BuildHead() { m_SmallHeadMan->SetHead(kThinMan); }
	void BuildBody() { m_SmallHeadMan->SetBody(kFatMan); }
	void BuildLeftHand() { m_SmallHeadMan->SetLeftHand(kFatMan); }
	void BuildRightHand() { m_SmallHeadMan->SetRightHand(kFatMan); }
	void BuildLeftFoot() { m_SmallHeadMan->SetLeftFoot(kFatMan); }
	void BuildRightFoot() { m_SmallHeadMan->SetRightFoot(kFatMan); }
	Man *GetMan() { return m_SmallHeadMan; }
private:
	Man *m_SmallHeadMan;
};


class Director
{
public:
	Director(Builder*builder) {
		m_Builder = builder;
	}

	void CreadeMan() {
		m_Builder->BuildHead();
		m_Builder->BuildBody();
		m_Builder->BuildLeftHand();
		m_Builder->BuildRightHand();
		m_Builder->BuildLeftFoot();
		m_Builder->BuildRightFoot();
	}

private:
	Builder* m_Builder;
};

int main()
{
	Builder *builderObj = new FatManBuilder();
	Director directorObj(builderObj);
	directorObj.CreadeMan();
	Man * ManObj = builderObj->GetMan();

	ManObj->ShowMan();

	delete ManObj;
	
	system("pause");
	return 0;
}

/**
有没有发现与抽象工厂很相似
抽象工厂是创建不同的类对象
建造者模式是创建的是相同的类的对象，只是用不同的方法对他们进行初始化。
*/