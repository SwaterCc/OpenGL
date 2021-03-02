#include "Mesh.h"


Mesh::Mesh(vector<vertexUnit> v, vector<size_t> i, vector<texture> t)
	:vertices(v),indices(i),textures(t)
{
	setupMesh();
}

void Mesh::draw()
{
	glBindVertexArray(m_pVertexConfig->getVAO());
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Mesh::update()
{
	//激活纹理单元

}

void Mesh::setupMesh()
{
	m_pVertexConfig = new VertexConfig();
	m_pVertexConfig->setVBO(vertices);
	m_pVertexConfig->setVEO(indices);
	m_pVertexConfig->setup(VERTEX_ATTRIB_POSITION|VERTEX_ATTRIB_TEXTURE| VERTEX_ATTRIB_NORMAL);
}
