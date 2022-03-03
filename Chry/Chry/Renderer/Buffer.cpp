#include "pch.hpp"
#include "Buffer.hpp"

namespace Chry
{
    /////////////////////////////////
    //        Vertex Buffer        //
    /////////////////////////////////

    VertexBuffer::VertexBuffer(float* vData, u32 vSize, const DrawType& vType)
        : mSize(vSize)
    {
        glGenBuffers(1, &mVertexBufferID);
        glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferID);
        glBufferData(GL_ARRAY_BUFFER, vSize, vData, DrawTypeToOpenGLType(vType));
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &mVertexBufferID);
    }

    void VertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferID);
    }

    void VertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    /////////////////////////////////
    //         Index Buffer        //
    /////////////////////////////////

    IndexBuffer::IndexBuffer(usi* vData, u32 vCount, const DrawType& vType)
        : mCount(vCount)
    {
        glGenBuffers(1, &mIndexBufferID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBufferID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, vCount * sizeof(usi), vData, DrawTypeToOpenGLType(vType));
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
		
    IndexBuffer::IndexBuffer(u32* vData, u32 vCount, const DrawType& vType)
        : mCount(vCount)
    {
        glGenBuffers(1, &mIndexBufferID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBufferID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, vCount * sizeof(u32), vData, DrawTypeToOpenGLType(vType));
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(1, &mIndexBufferID);
    }

    void IndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBufferID);
    }

    void IndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    /////////////////////////////////
    //         Vertex Array        //
    /////////////////////////////////
    
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &mVertexArrayID);
        glBindVertexArray(mVertexArrayID);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &mVertexArrayID);
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(mVertexArrayID);
    }

    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    void VertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vVertexBuffer)
    {
		ASSERT(vVertexBuffer->GetBufferLayout().GetElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(mVertexArrayID);
		vVertexBuffer->Bind();

		uint32_t index = 0;
		for( const auto& element : vVertexBuffer->GetBufferLayout())
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index, 
				element.GetComponentCount(), 
				ShaderDataTypeToOpenGLType(element.Type), 
				element.Normalized ? GL_TRUE : GL_FALSE, 
				vVertexBuffer->GetBufferLayout().GetStride(), 
				(const void*)element.Offset
			);

			index++;
		}

		mVertexBuffers.push_back(vVertexBuffer);
    }
    
    void VertexArray::SetIndexBuffer(const Ref<IndexBuffer>& vIndexBuffer)
    {
		glBindVertexArray(mVertexArrayID);
		vIndexBuffer->Bind();

		mIndexBuffer = vIndexBuffer;
    }
}
