#pragma once
#include <algorithm>

#define Ogr ObjectMgr::GetInst()


class ObjectMgr : public Singleton<ObjectMgr>
{
public:
	std::list<Object*> m_Objects;
	struct stLISTsort
	{
		bool operator() (const Object* pObject1, const Object* pObject2) const
		{
			if (pObject1->m_Layer < pObject2->m_Layer)
				return TRUE;

			return FALSE;
		}
	};

public:
	ObjectMgr();
	virtual ~ObjectMgr();


	
	void Release();
	void DeleteCheak();
	void Update(float time);
	void CollideCheak(Object* obj, std::string tag);
	void Render();




public:
	void KeepObject(Object* obj, std::string tag);
	void RemoveObject(Object* obj);

};

