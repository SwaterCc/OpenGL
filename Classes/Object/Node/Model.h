#ifndef _Model_h_
#define _Model_h_

#include"ObjectBase.h"
#include<assimp/Importer.hpp>
#include<assimp/scene.h>
#include<assimp/postprocess.h>
#include"Mesh.h"

class Model : public ObjectBase
{
public:
	static Model* create(const char* file);
	
	void update() override;
	void draw() override;
protected:
	Model(const char* file);
	void loadModel(const char* filePath);
	void processNode(aiNode* node,const aiScene* scene);
	Mesh processMesh(aiMesh* mesh,const aiScene* scene);
	vector<TextureIndex> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);
private:
	vertexUnit processVertex(aiMesh* mesh, size_t i);
	
	vector<TextureIndex> processMaterial(aiMesh* mesh);
	const aiScene* scene;
	vector<Mesh> meshes;
	string directory;

	vector<TextureIndex> textures_loaded;//Œ∆¿Ìª∫¥Ê

};

#endif
