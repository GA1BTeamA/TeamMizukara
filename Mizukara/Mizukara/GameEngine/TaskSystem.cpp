//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "TaskSystem.h"

//���X�g�@CObj�����I�u�W�F�N�g
list<shared_ptr<CObj>>* CTaskSystem::m_task_list;

void CTaskSystem::InitTaskSystem()
{
	//���X�g�쐬
	m_task_list = new list<shared_ptr<CObj>>();
}

void CTaskSystem::DeleteTaskSystem()
{
	//���X�g�j��
	delete m_task_list;
}

//���X�g���̃I�u�W�F�N�g���v���C�I���e�B���Ƀ\�[�g�i�A�N�V�����p�j
void CTaskSystem::SortActionPriority()
{
	//�\�[�g��r�N���X
	class Pr
	{
	public:
		bool operator()(const shared_ptr<CObj> x, const shared_ptr<CObj> y)const
		{
			//��r����v�f�Ɠ��e�����߂�
			return x.get()->m_ActionPriority < y.get()->m_ActionPriority;
		}
	}pr;

	//�v�f��2�ȏ㖳���ƃ\�[�g�̓G���[����
	if (m_task_list->size() >= 2)
	{
		//���X�g���r�N���X�����Ƀ\�[�g���s
		m_task_list->sort(pr);
	}
}

//���X�g���̃I�u�W�F�N�g���v���C�I���e�B���Ƀ\�[�g�i�h���[�p�j
void CTaskSystem::SortDrawPriority()
{
	//�\�[�g��r�N���X
	class Pr
	{
	public:
		bool operator()(const shared_ptr<CObj> x, const shared_ptr<CObj> y)const
		{
			//��r����v�f�Ɠ��e�����߂�
			return x.get()->m_DrawPriority < y.get()->m_DrawPriority;
		}
	}pr;

	//�v�f��2�ȏ㖳���ƃ\�[�g�̓G���[����
	if (m_task_list->size() >= 2)
	{
		//���X�g���r�N���X�����Ƀ\�[�g���s
		m_task_list->sort(pr);
	}
}

//�ǉ�
void CTaskSystem::InsertObj(CObj* obj)
{
	//�V�F�A�|�C���^�ɃI�u�W�F�N�g�̃A�h���X���i�[
	shared_ptr<CObj>sp;
	sp.reset(obj);

	//���X�g�̖��[�Ɋi�[�����I�u�W�F�N�g��ǉ�
	m_task_list->push_back(sp);

}

//���X�g���̃A�N�V�������s
void CTaskSystem::ListAction()
{
	//���X�g����is_delete��true�̗v�f���폜
	auto i = m_task_list->begin();
	while (i != m_task_list->end())
	{
		if (i->get()->is_delete == true)
		{
			//�C�e���[�^i�̗v�f���폜
			i = m_task_list->erase(i);
		}
		else
		{
			i++;
		}
	}

	//���X�g�̐�[���疖�[�܂�
	for (auto ip = m_task_list->begin(); ip != m_task_list->end(); ip++)
	{
		//���X�g���̃I�u�W�F�N�g�����A�N�V�������\�b�h�����s
		if (ip->get()->is_delete == false) {
			ip->get()->Action();
		}
	}
}

//���X�g���̃h���[���s
void CTaskSystem::ListDraw()
{
	//���X�g�̐�[���疖�[�܂�
	for (auto ip = m_task_list->begin(); ip != m_task_list->end(); ip++)
	{
		//���X�g���̃I�u�W�F�N�g�����h���[���\�b�h�����s
			ip->get()->Draw();
	}
}

//�I�u�W�F�N�g���擾
CObj* CTaskSystem::GetObj(unsigned int n)
{
	for (auto itr = m_task_list->begin(); itr != m_task_list->end(); itr++)
	{
		if ((*itr)->GetName() == n)
			return (*itr).get();
	}

	return NULL;
}

void CTaskSystem::TaskClear()
{
	//���X�g�̐�[���疖�[�܂�
	auto BeginObj = m_task_list->begin();
	for (auto ip = m_task_list->begin(); ip != m_task_list->end(); ip++)
	{
		//���X�g���̃I�u�W�F�N�g�����h���[���\�b�h�����s
		if(ip!=BeginObj)
			ip->get()->is_delete=true;
	}
}

