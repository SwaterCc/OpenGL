#ifndef _Mesh_h_
#define _Mesh_h_
#include "../../Utility/glmath/glmathlib.h"
#include "../../Framework/GLProgram.h"
#include "../Attribute/VertexConfig.h"
#include <assimp/Importer.hpp>

#include<vector>
#include<iostream>
#include<string>
using namespace std;

//typedef struct Vertex
//{
//	glmath::vec3 pos;
//	glmath::vec3 normal;
//	glmath::vec2 texcoord;
//	glmath::vec3 tangent;//����
//	glmath::vec3 bitangent;//˫����
//}vertex;


typedef struct TextureIndex
{
	size_t id;
	string type;
	aiString path;

}texture;

class Mesh
{
public:
	Mesh(vector<vertexUnit> v, vector<size_t> i, vector<texture>t);
	void draw();
	void update();
private:
	void setupMesh();
private:

	vector<vertexUnit> vertices;//���㼯��
	vector<size_t> indices; //��������
	vector<texture> textures;//������������

	VertexConfig* m_pVertexConfig;
};



#endif // !_Mesh_h_

