#include "Model.h"
#include "../Texture/Texture2D.h"

Model* Model::create(const char* file)
{
	Model* p = new Model(file);
	if (p)
	{
		return p;
	}
	return nullptr;
}

void Model::update()
{
	ObjectBase::update();
	for (int i = 0; i < meshes.size(); i++)
		meshes[i].update();
}

void Model::draw()
{
	for (int i = 0; i < meshes.size(); i++)
		meshes[i].draw();
}

Model::Model(const char* file)
{
	scene = nullptr;
	loadModel(file);
}

void Model::loadModel(const char* filePath)
{
	Assimp::Importer importer;
	scene = importer.ReadFile(filePath, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		cerr << "ERROR::ASSIMP::" << importer.GetErrorString() << endl;
		return;
	}
	string path = filePath;
	directory = path.substr(0, path.find_last_of('/'));

	processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
	//处理自身节点所有的网格
	for (auto i = 0; i < node->mNumMeshes; i++)
	{
		auto* mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(processMesh(mesh, scene));
	}
	//处理子节点
	for (auto i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene);
	}
}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
	vector<vertexUnit> vertices;
	vector<uint> indices;
	//顶点属性
	for (size_t i = 0; i < mesh->mNumVertices; i++)
	{
		vertices.push_back(processVertex(mesh,i));
	}
	//索引
	for (size_t i = 0; i < mesh->mNumFaces; i++)
	{
		auto face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++)
		{
			indices.push_back(face.mIndices[j]);
		}
	}
	//材质
	vector<TextureIndex> textures = processMaterial(mesh);

	return Mesh(vertices, indices, textures);
}

vertexUnit Model::processVertex(aiMesh* mesh, size_t i)
{
	vertexUnit tmp;
	
	auto v = mesh->mVertices[i];

	tmp.vertex.x = v.x;
	tmp.vertex.y = v.y;
	tmp.vertex.z = v.z;
	
	tmp.color.r = 1;
	tmp.color.g = 1;
	tmp.color.b = 1;
	
	auto n = mesh->mNormals[i];

	tmp.normal.x = n.x;
	tmp.normal.y = n.y;
	tmp.normal.z = n.z;

	if (mesh->mTextureCoords[0])
	{
		auto t = mesh->mTextureCoords[0][i];//默认找第一个纹理

		tmp.texture.x = t.x;
		tmp.texture.y = t.y;
	}
	else
		tmp.texture = { 0,0 };

	// tangent
	tmp.tangent.x = mesh->mTangents[i].x;
	tmp.tangent.y = mesh->mTangents[i].y;
	tmp.tangent.z = mesh->mTangents[i].z;
	
	// bitangent
	tmp.bitangent.x = mesh->mBitangents[i].x;
	tmp.bitangent.y = mesh->mBitangents[i].y;
	tmp.bitangent.z = mesh->mBitangents[i].z;


	return tmp;
}

vector<TextureIndex> Model::processMaterial(aiMesh* mesh)
{
	vector<TextureIndex> textures;
	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
		vector<TextureIndex> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

		vector<TextureIndex> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());

		// 3. normal maps
		std::vector<TextureIndex> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
		textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
		// 4. height maps
		std::vector<TextureIndex> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
		textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

	}
	return textures;
}


vector<TextureIndex> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName)
{
	vector<TextureIndex> textures;

	for (uint i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str);
		bool skip = false;

		for (uint j = 0; j < textures_loaded.size(); j++)
		{
			if (std::strcmp(textures_loaded[j].path.data, str.C_Str()))
			{
				textures.push_back(textures_loaded[j]);
				skip = true;
				break;
			}
		}
		if (!skip)
		{
			TextureIndex tmp;
			string path = "model/" + directory + '/' + str.C_Str();
			tmp.id = Texture2D::create(path)->getTex();
			tmp.type = typeName;
			tmp.path = str;
			textures.push_back(tmp);
			textures_loaded.push_back(tmp);
		}
	}


	return textures;
}
