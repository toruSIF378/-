#include"DxLib.h"
#include "ImageMng.h"

//-----�摜�o�^(1������)
void ImageMng::SetID(std::string idName, std::string fileName)
//const int& ImageMng::SetID(std::string idName, std::string fileName)
{
	//map�z��Ŋ��ɓo�^�ς��ǂ������`�F�b�N����
	//�o�^���Ȃ����LoadGraph����ID��map�z��ɒǉ�
	//std::map<std::string,int>imgDivMap;

	if (imgMap.find(idName) == imgMap.end()) 
	{
		imgMap[idName] = LoadGraph(fileName.c_str());
	}
	//return imgMap[idName]; //�o�^����ID��Ԃ�(���s����-1)

}
//-----�摜�o�^(�A�j���[�V����)
void ImageMng::SetID(std::string idName, std::string fileName, VECTOR2 divSize, VECTOR2 divNum)
{
	//map�z��Ŋ��ɓo�^�ς��ǂ������`�F�b�N����
	//�o�^���Ȃ����LoadGraph����ID��map�z��ɒǉ�
	//std::map<std::string,std::vector<int>>imgDivMap;

	if (imgDivMap.find(idName) == imgDivMap.end())
	{
		//���I�ȗv�f����ݒ�(vector�^�z��)
		imgDivMap[idName].resize(divNum.x*divNum.y);

		LoadDivGraph(fileName.c_str(), divNum.x*divNum.y,
					divNum.x, divNum.y, 
					divSize.x, divSize.y, 
					&imgDivMap[idName][0], true);
	}
	//return imgDivMap[idName];
}

//-----�摜�`��(1������)
void ImageMng::DrawImage(std::string idName, int x, int y, bool flag)
{
	//�`��v���̂�����ID��T����
	//�o�^���Ȃ���Ζ����A����Ε`��

	if (imgMap.find(idName) == imgMap.end()) 
	{
		return;
	}
	DrawGraph(x, y, imgMap[idName], flag);
}

//-----�摜�`��(�A�j���[�V����)
void ImageMng::DrawImage(std::string idName, int x, int y, int animNo, bool flag)
{
	//�`��v���̂�����ID��T����
	//�o�^���Ȃ���Ζ����A����Ε`��
	if (imgDivMap.find(idName) == imgDivMap.end())
	{
		return;
	}

	//animNo���z��̃T�C�Y�𒴂��Ă�����return
	if ((animNo<0) || imgDivMap[idName].size() <= animNo) {
		return;
	}

	DrawGraph(x, y, imgDivMap[idName][animNo], flag);
}


