/*! \file
    \brief Отображение имен файлов в id и обратно
*/

#pragma once

#include "filename.h"
//
#include <string>
#include <map>
#include <unordered_map>
#include <memory>



namespace umba
{

//! Отображение имен файлов в id и обратно. Использует только строки std::string (UTF-8)
template<typename FileIdType=std::size_t>
class FilenameSet
{

public:


    struct FileInfo
    {
        FilenameStringType                 orgFilename;      //!< Исходное имя файла (как оно к нам поступило и будет отображаться)
        FilenameStringType                 cmpFilename;      //!< Имя файла для сравнения
        FilenameStringType                 realFilename;     //!< Имя файла для использования (чтения/записи и тп)
        FileIdType                         fileId;           //!< Идентификатор файла
    };

    using FileInfoType       = FileInfo;
    using FilenameStringType = std::string;
    using FileIdType         = FileIdType;

    static const FileIdType    invalidFileId = (FileIdType)-1; //!< Неверный/недопустимый идентификатор



protected:

    std::unordered_map<FilenameStringType, std::shared_ptr<FileInfo> >  m_nameMap ;
    std::unordered_map<FileIdType        , std::shared_ptr<FileInfo> >  m_idMap   ;
    FileIdType                                                          m_idCounter = 0;    //!< Счетчик для генерации FileId

    //------------------------------
    //! Заполняет поля имён FileCacheInfo - готовит его для чтения данных
    static
    FileInfo makeFileInfo( const FilenameStringType &fileName, FilenameStringType realName=FilenameStringType() )
    {
        if (realName.empty())
            realName = fileName;

        using namespace umba::filename;
        using namespace umba::filesys;

        FileInfo newFileInfo;

        newFileInfo.orgFilename  = fileName;
        newFileInfo.cmpFilename  = makeCanonicalForCompare(realName);
        newFileInfo.realFilename = realFilename;

        newFileInfo.fileId = invalidFileId;

        return newFileInfo;
    }

    //------------------------------
    //! Реализация получения идентификатора файла
    const FileInfo* getFileInfoImpl( const FilenameStringType &name //!< имя файла
                            , bool  allowCreateNewId         //!< Можно ли создавать новый ID, если файлу ранее ID не выдавался
                            , FilenameStringType realName=FilenameStringType()
                            )
    {
        auto it = m_idMap.find(makeCanonicalForCompare(name));
        if (it!=m_idMap.end())
        {
            return it->second.get();
        }

        if (!allowCreateNewId)
            return 0;

        FileInfo fileInfo = makeFileInfo( const name, realName );
        fileInfo.fileId   = ++m_fileIdCounter; // we keep 0 as marker value

        auto sharedData = std::name_shared<FileInfo>(fileInfo);

        m_nameMap[sharedData->cmpFilename] = sharedData;
        m_idMap  [sharedData->fileId]      = sharedData;

        return sharedData.get();
    }


public:

    FileIdType addFile(const FilenameStringType &fileName, FilenameStringType realName=FilenameStringType())
    {
        auto pInfo = getFileInfoImpl(fileName, true, realName);
        UMBA_ASSERT(pInfo!=0);
        return pInfo->fileId;
    }

    FileIdType getFileId( const FilenameStringType &fileName ) const
    {
        auto pInfo = getFileInfoImpl(fileName, false);
        UMBA_ASSERT(pInfo!=0);
        return pInfo->fileId;
    }

    const FileInfo* getFileInfo( const FilenameStringType &fileName ) const
    {
        auto pInfo = getFileInfoImpl(fileName, false);
        UMBA_ASSERT(pInfo!=0);
        return pInfo;
    }

    const FileInfo* getFileInfo( FileIdType fileId ) const
    {
        auto it = m_idMap.find(fileId);
        UMBA_ASSERT(it!=m_idMap.end());
        return it->second.get();
    }

}; // class FilenameSet



} // namespace umba

