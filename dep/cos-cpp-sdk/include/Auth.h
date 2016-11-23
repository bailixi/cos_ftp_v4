#ifndef AUTH_H
#define AUTH_H

#include <stdint.h>
#include <string>

using std::string;
namespace qcloud_cos {

class Auth {
public:
    /// @brief ���ض����Ч��ǩ������������Ч�����ظ��Զ����Դʹ�ã����²������������qcloud������
    ///        ��ȡ������https://www.qcloud.com/doc/product/227/%E5%9F%BA%E6%9C%AC%E6%A6%82%E5%BF%B5
    /// @param app_id ��Ŀ��app_id
    /// @param secret_id ǩ����Կid�����ڿ���̨���
    /// @param secret_key ǩ����Կ�����ڿ���̨���
    /// @param expired_time_in_s ����ʱ�䣬�ӵ�ǰ��ʼ�Ĺ���ʱ�䣬��λ��
    /// @param bucket_name �ļ����ڵ�bucket
    /// @return string ǩ���������ڷ����ļ������ؿմ�����ʧ��
    static std::string AppSignMuti(uint64_t app_id,
                                   const std::string& secret_id,
                                   const std::string& secret_key,
                                   uint64_t expired_time_in_s,
                                   const std::string& bucket_name);

    /// @brief ���ص�����Ч��ǩ��������ɾ���͸���ָ��path����Դ������ʹ��һ��
    ///        ��ȡ������https://www.qcloud.com/doc/product/227/%E5%9F%BA%E6%9C%AC%E6%A6%82%E5%BF%B5
    /// @param app_id ��Ŀ��app_id
    /// @param secret_id ǩ����Կid�����ڿ���̨���
    /// @param secret_key ǩ����Կ�����ڿ���̨���
    /// @param path �ļ���bucket�е�λ��
    /// @param bucket_name �ļ����ڵ�bucket�����ؿմ�����ʧ��
    /// @return string ǩ���������ڷ����ļ�
    static std::string AppSignOnce(uint64_t app_id,
                                   const std::string& secret_id,
                                   const std::string& secret_key,
                                   const std::string& path,
                                   const std::string& bucket_name);


private:
    static std::string AppSignInternal(uint64_t app_id,
                                       const std::string& secret_id,
                                       const std::string& secret_key,
                                       uint64_t expired_time_in_s,
                                       const std::string& file_id,
                                       const std::string& bucket_name);

private:
    // ��ֹ������ֹ���
    Auth() {}
    ~Auth() {}

    Auth(const Auth&);
    Auth& operator=(const Auth&);
};

} // namespace qcloud_cos

#endif // AUTH_H
