#pragma once

template<class T>

//c ++���� Ŭ���� T�� ����ϴ� ���� �� �ϳ��� ������ ������ �ٸ� �Լ�(�� : int main)�� 
//���ǵǾ��ִ� ��� �Լ����� ������ ������ �������ϴ� �ð��� ���̴� ���Դϴ�.

class Singleton  //�̱��� ������ �� �ϳ��� �ν��Ͻ��� ������ ����ϴ� ������ �����̴�.                                     
{
private:
	static T* m_Instance;

public:

	static T* GetInst()
	{
		if (m_Instance == 0)
			m_Instance = new T();

		return m_Instance;
	}

};

template<class T>
T* Singleton<T>::m_Instance = 0;