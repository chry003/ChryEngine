#include "pch.hpp"
#include "Renderer.hpp"

namespace Chry
{

    std::unordered_map<sstr, svec<Ref<VertexArray>>> Renderer::mStoragePoint;

    void Renderer::Begin()
    {

    }

    void Renderer::End()
    {

    }
    
    void Renderer::InitStoragePoint(const sstr& vName)
    {
        if(mStoragePoint.find(vName) == mStoragePoint.end())
            mStoragePoint[vName] = svec<Ref<VertexArray>>();
        else
            ASSERT(false, "Storage is already set for this key.")
    }

    void Renderer::PushToStoragePoint(const sstr& vName, const Ref<VertexArray> &vVertexArray)
    {
        if(mStoragePoint.find(vName) == mStoragePoint.end())
            ASSERT(false, "Storage is not set for this key.")
        else
            mStoragePoint.find(vName)->second.push_back(vVertexArray);
    }

    void Renderer::RemoveStoragePoint(const sstr &vName)
    {
        if(mStoragePoint.find(vName) == mStoragePoint.end())
            ASSERT(false, "Storage is not set for this key.")
        else
            mStoragePoint.erase(vName);
    }

    void Renderer::DrawFromStoragePoint(const sstr& vName)
    {
        if(mStoragePoint.find(vName) == mStoragePoint.end())
            ASSERT(false, "Storage is not set for this key")
        else
        {
            for(u32 i = 0; i < mStoragePoint.find(vName)->second.size(); i++)
            {
                Renderer::Draw(mStoragePoint.find(vName)->second[i]);
            }
        }
    }
}
