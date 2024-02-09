#include "Shape.h"
#include <vector>
#include "glad/glad.h"
#include "../../Buffer/VertexArray.h"
#include "../../Buffer/ElementBuffer.h"
#include "Line.h"

namespace Dungeoneering {

    void Shape::render() {
        std::vector<Vec3<GLfloat>> vertices;

        for (Segment* segment: this->segments) {
            if(segment->getType() == SEGMENT_TYPE::LINE){
                Line* line = dynamic_cast<Line*>(segment);
                vertices.push_back(Vec3<GLfloat>((float)line->getStart().x,(float)line->getStart().y,0));
                vertices.push_back(Vec3<GLfloat>((float)line->getEnd().x,(float)line->getEnd().y,0));
            }
        }

        std::vector<GLuint> ind;
        for (int i = 0; i < vertices.size(); ++i) {
            ind.push_back(i);
        }

        VertexArray VAO;
        VAO.bind();

        VertexBuffer VBO(vertices);
        VBO.bind();
        ElementBuffer EBO(ind);
        EBO.bind();

        VAO.linkVBO(VBO, 0);


        glDrawElements(GL_LINES, (int)vertices.size() * 3, GL_UNSIGNED_INT, nullptr);

        VBO.unbind();
        EBO.unbind();
        VAO.unbind();
    }

    void Shape::addSegment(Segment* segment) {
        this->segments.push_back(segment);
    }
}
