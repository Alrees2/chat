<!DOCTYPE html>
<html lang="ar" dir="rtl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>SocialVerse - منصة التواصل الاجتماعي</title>
    <!-- Font Awesome -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css">
    <!-- Google Fonts -->
    <link href="https://fonts.googleapis.com/css2?family=Tajawal:wght@400;500;700;900&display=swap" rel="stylesheet">
    <style>
        :root {
            --primary: #6c5ce7;
            --primary-dark: #5649c0;
            --secondary: #00cec9;
            --accent: #fd79a8;
            --light: #f5f6fa;
            --dark: #2d3436;
            --gray: #dfe6e9;
            --dark-gray: #636e72;
            --success: #00b894;
            --danger: #d63031;
            --warning: #fdcb6e;
            
            --shadow: 0 4px 12px rgba(0, 0, 0, 0.1);
            --shadow-lg: 0 8px 24px rgba(0, 0, 0, 0.15);
            --transition: all 0.3s cubic-bezier(0.25, 0.8, 0.25, 1);
        }

        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Tajawal', sans-serif;
        }

        body {
            background-color: var(--light);
            color: var(--dark);
            overflow-x: hidden;
        }

        /* Welcome Screen */
        .welcome-screen {
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: linear-gradient(135deg, var(--primary), var(--secondary));
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            z-index: 1000;
            transition: var(--transition);
        }

        .welcome-screen.hidden {
            opacity: 0;
            pointer-events: none;
        }

        .welcome-logo {
            font-size: 4rem;
            color: white;
            margin-bottom: 2rem;
            animation: pulse 2s infinite;
        }

        .welcome-title {
            font-size: 2.5rem;
            color: white;
            margin-bottom: 1rem;
            text-align: center;
        }

        .welcome-subtitle {
            font-size: 1.2rem;
            color: rgba(255, 255, 255, 0.9);
            margin-bottom: 3rem;
            text-align: center;
            max-width: 80%;
        }

        .welcome-buttons {
            display: flex;
            gap: 1rem;
        }

        .welcome-btn {
            padding: 1rem 2rem;
            border-radius: 50px;
            border: none;
            font-size: 1.1rem;
            font-weight: 700;
            cursor: pointer;
            transition: var(--transition);
            display: flex;
            align-items: center;
            gap: 0.5rem;
        }

        .welcome-btn-primary {
            background-color: white;
            color: var(--primary);
        }

        .welcome-btn-secondary {
            background-color: transparent;
            color: white;
            border: 2px solid white;
        }

        .welcome-btn:hover {
            transform: translateY(-5px);
            box-shadow: var(--shadow-lg);
        }

        /* Auth Modals */
        .auth-modal {
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background-color: rgba(0, 0, 0, 0.7);
            display: flex;
            justify-content: center;
            align-items: center;
            z-index: 1001;
            opacity: 0;
            pointer-events: none;
            transition: var(--transition);
        }

        .auth-modal.active {
            opacity: 1;
            pointer-events: all;
        }

        .auth-container {
            background-color: white;
            border-radius: 20px;
            width: 90%;
            max-width: 500px;
            overflow: hidden;
            transform: scale(0.9);
            transition: var(--transition);
            box-shadow: var(--shadow-lg);
        }

        .auth-modal.active .auth-container {
            transform: scale(1);
        }

        .auth-header {
            background: linear-gradient(135deg, var(--primary), var(--secondary));
            color: white;
            padding: 1.5rem;
            text-align: center;
            position: relative;
        }

        .auth-title {
            font-size: 1.5rem;
            margin-bottom: 0.5rem;
        }

        .auth-subtitle {
            font-size: 0.9rem;
            opacity: 0.9;
        }

        .close-auth {
            position: absolute;
            top: 1rem;
            left: 1rem;
            background: none;
            border: none;
            color: white;
            font-size: 1.5rem;
            cursor: pointer;
        }

        .auth-body {
            padding: 2rem;
        }

        .auth-form-group {
            margin-bottom: 1.5rem;
        }

        .auth-form-group label {
            display: block;
            margin-bottom: 0.5rem;
            font-weight: 500;
        }

        .auth-form-control {
            width: 100%;
            padding: 0.8rem 1rem;
            border: 1px solid var(--gray);
            border-radius: 10px;
            font-size: 1rem;
            transition: var(--transition);
        }

        .auth-form-control:focus {
            border-color: var(--primary);
            outline: none;
            box-shadow: 0 0 0 3px rgba(108, 92, 231, 0.2);
        }

        .auth-footer {
            text-align: center;
            margin-top: 1.5rem;
        }

        .auth-submit-btn {
            background: linear-gradient(135deg, var(--primary), var(--secondary));
            color: white;
            border: none;
            padding: 1rem 2rem;
            border-radius: 10px;
            font-size: 1.1rem;
            font-weight: 700;
            cursor: pointer;
            width: 100%;
            transition: var(--transition);
        }

        .auth-submit-btn:hover {
            transform: translateY(-3px);
            box-shadow: var(--shadow-lg);
        }

        .auth-switch-text {
            margin-top: 1rem;
            font-size: 0.9rem;
        }

        .auth-switch-btn {
            background: none;
            border: none;
            color: var(--primary);
            font-weight: 700;
            cursor: pointer;
            margin-right: 0.3rem;
        }

        /* Main App */
        .app-container {
            display: none;
            max-width: 100vw;
            min-height: 100vh;
        }

        .app-container.active {
            display: block;
        }

        /* Header */
        .app-header {
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            background-color: white;
            box-shadow: var(--shadow);
            padding: 1rem;
            display: flex;
            justify-content: space-between;
            align-items: center;
            z-index: 100;
        }

        .logo {
            font-size: 1.8rem;
            font-weight: 700;
            color: var(--primary);
            display: flex;
            align-items: center;
            gap: 0.5rem;
        }

        .logo i {
            color: var(--secondary);
        }

        .header-actions {
            display: flex;
            align-items: center;
            gap: 1rem;
        }

        .header-icon {
            font-size: 1.5rem;
            color: var(--dark-gray);
            cursor: pointer;
            position: relative;
            transition: var(--transition);
        }

        .header-icon:hover {
            color: var(--primary);
        }

        .notification-badge {
            position: absolute;
            top: -5px;
            right: -5px;
            background-color: var(--danger);
            color: white;
            border-radius: 50%;
            width: 18px;
            height: 18px;
            font-size: 0.7rem;
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .user-avatar {
            width: 40px;
            height: 40px;
            border-radius: 50%;
            object-fit: cover;
            cursor: pointer;
            border: 2px solid var(--primary);
        }

        /* Stories */
        .stories-container {
            padding: 1rem;
            margin-top: 70px;
            overflow-x: auto;
            white-space: nowrap;
            scrollbar-width: none;
        }

        .stories-container::-webkit-scrollbar {
            display: none;
        }

        .story {
            display: inline-block;
            width: 80px;
            height: 120px;
            border-radius: 15px;
            margin-right: 1rem;
            background: linear-gradient(45deg, var(--primary), var(--accent));
            position: relative;
            cursor: pointer;
            box-shadow: var(--shadow);
            transition: var(--transition);
        }

        .story:hover {
            transform: translateY(-5px);
            box-shadow: var(--shadow-lg);
        }

        .story-avatar {
            position: absolute;
            top: 10px;
            left: 10px;
            width: 40px;
            height: 40px;
            border-radius: 50%;
            object-fit: cover;
            border: 3px solid white;
        }

        .story-username {
            position: absolute;
            bottom: 10px;
            left: 10px;
            color: white;
            font-weight: 500;
            font-size: 0.8rem;
            text-shadow: 0 1px 3px rgba(0, 0, 0, 0.3);
        }

        .add-story {
            background: var(--gray);
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
        }

        .add-story i {
            font-size: 1.5rem;
            color: var(--dark);
            margin-bottom: 0.5rem;
        }

        .add-story span {
            color: var(--dark);
            font-size: 0.8rem;
        }

        /* Posts */
        .feed-container {
            padding: 1rem;
            max-width: 600px;
            margin: 0 auto;
            padding-bottom: 70px;
        }

        .post {
            background-color: white;
            border-radius: 15px;
            margin-bottom: 1.5rem;
            box-shadow: var(--shadow);
            overflow: hidden;
            transition: var(--transition);
        }

        .post:hover {
            transform: translateY(-3px);
            box-shadow: var(--shadow-lg);
        }

        .post-header {
            display: flex;
            align-items: center;
            padding: 1rem;
        }

        .post-avatar {
            width: 40px;
            height: 40px;
            border-radius: 50%;
            object-fit: cover;
            margin-left: 0.5rem;
        }

        .post-user-info {
            flex: 1;
        }

        .post-username {
            font-weight: 700;
            font-size: 0.95rem;
        }

        .post-time {
            font-size: 0.8rem;
            color: var(--dark-gray);
        }

        .post-more {
            color: var(--dark-gray);
            cursor: pointer;
        }

        .post-content {
            padding: 0 1rem 1rem;
        }

        .post-text {
            margin-bottom: 1rem;
            line-height: 1.5;
        }

        .post-image {
            width: 100%;
            border-radius: 10px;
            margin-bottom: 1rem;
            max-height: 500px;
            object-fit: cover;
        }

        .post-actions {
            display: flex;
            justify-content: space-between;
            padding: 0 1rem 1rem;
            border-bottom: 1px solid var(--gray);
        }

        .post-action {
            display: flex;
            align-items: center;
            gap: 0.3rem;
            color: var(--dark-gray);
            cursor: pointer;
            transition: var(--transition);
        }

        .post-action:hover {
            color: var(--primary);
        }

        .post-action.liked {
            color: var(--danger);
        }

        .post-comments {
            padding: 1rem;
        }

        .comment {
            display: flex;
            margin-bottom: 1rem;
        }

        .comment-avatar {
            width: 30px;
            height: 30px;
            border-radius: 50%;
            object-fit: cover;
            margin-left: 0.5rem;
        }

        .comment-content {
            flex: 1;
            background-color: var(--gray);
            padding: 0.7rem;
            border-radius: 10px;
        }

        .comment-username {
            font-weight: 700;
            font-size: 0.85rem;
            margin-bottom: 0.2rem;
        }

        .comment-text {
            font-size: 0.9rem;
            line-height: 1.4;
        }

        .add-comment {
            display: flex;
            align-items: center;
            margin-top: 1rem;
        }

        .comment-input {
            flex: 1;
            padding: 0.7rem 1rem;
            border: 1px solid var(--gray);
            border-radius: 50px;
            font-size: 0.9rem;
            transition: var(--transition);
        }

        .comment-input:focus {
            border-color: var(--primary);
            outline: none;
        }

        .comment-submit {
            background: none;
            border: none;
            color: var(--primary);
            font-size: 1.2rem;
            margin-right: 0.5rem;
            cursor: pointer;
        }

        /* Bottom Navigation */
        .bottom-nav {
            position: fixed;
            bottom: 0;
            left: 0;
            width: 100%;
            background-color: white;
            box-shadow: 0 -4px 12px rgba(0, 0, 0, 0.1);
            display: flex;
            justify-content: space-around;
            padding: 0.8rem 0;
            z-index: 100;
        }

        .nav-item {
            display: flex;
            flex-direction: column;
            align-items: center;
            color: var(--dark-gray);
            cursor: pointer;
            transition: var(--transition);
        }

        .nav-item.active {
            color: var(--primary);
        }

        .nav-item:hover {
            color: var(--primary);
        }

        .nav-icon {
            font-size: 1.5rem;
        }

        .nav-text {
            font-size: 0.7rem;
            margin-top: 0.2rem;
        }

        /* Create Post Modal */
        .create-post-modal {
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background-color: rgba(0, 0, 0, 0.7);
            display: flex;
            justify-content: center;
            align-items: center;
            z-index: 1001;
            opacity: 0;
            pointer-events: none;
            transition: var(--transition);
        }

        .create-post-modal.active {
            opacity: 1;
            pointer-events: all;
        }

        .create-post-container {
            background-color: white;
            border-radius: 20px;
            width: 90%;
            max-width: 500px;
            overflow: hidden;
            transform: scale(0.9);
            transition: var(--transition);
            box-shadow: var(--shadow-lg);
        }

        .create-post-modal.active .create-post-container {
            transform: scale(1);
        }

        .create-post-header {
            padding: 1.5rem;
            text-align: center;
            position: relative;
            border-bottom: 1px solid var(--gray);
        }

        .create-post-title {
            font-size: 1.3rem;
            font-weight: 700;
        }

        .close-create-post {
            position: absolute;
            top: 1.5rem;
            left: 1.5rem;
            background: none;
            border: none;
            color: var(--dark-gray);
            font-size: 1.5rem;
            cursor: pointer;
        }

        .create-post-body {
            padding: 1.5rem;
        }

        .post-form-group {
            margin-bottom: 1.5rem;
        }

        .post-form-control {
            width: 100%;
            padding: 1rem;
            border: 1px solid var(--gray);
            border-radius: 10px;
            font-size: 1rem;
            resize: none;
            min-height: 100px;
            transition: var(--transition);
        }

        .post-form-control:focus {
            border-color: var(--primary);
            outline: none;
        }

        .image-preview {
            margin-top: 1rem;
            display: none;
            position: relative;
        }

        .image-preview.active {
            display: block;
        }

        .preview-image {
            width: 100%;
            border-radius: 10px;
            max-height: 300px;
            object-fit: cover;
        }

        .remove-image {
            position: absolute;
            top: 10px;
            left: 10px;
            background-color: var(--danger);
            color: white;
            border: none;
            width: 30px;
            height: 30px;
            border-radius: 50%;
            display: flex;
            justify-content: center;
            align-items: center;
            cursor: pointer;
        }

        .image-upload-btn {
            display: flex;
            align-items: center;
            justify-content: center;
            gap: 0.5rem;
            background-color: var(--light);
            border: 1px dashed var(--dark-gray);
            border-radius: 10px;
            padding: 1rem;
            cursor: pointer;
            transition: var(--transition);
        }

        .image-upload-btn:hover {
            background-color: var(--gray);
        }

        .create-post-footer {
            padding: 1rem 1.5rem;
            display: flex;
            justify-content: flex-end;
        }

        .post-submit-btn {
            background: linear-gradient(135deg, var(--primary), var(--secondary));
            color: white;
            border: none;
            padding: 0.8rem 1.5rem;
            border-radius: 10px;
            font-size: 1rem;
            font-weight: 700;
            cursor: pointer;
            transition: var(--transition);
        }

        .post-submit-btn:hover {
            transform: translateY(-3px);
            box-shadow: var(--shadow-lg);
        }

        /* Responsive */
        @media (max-width: 768px) {
            .welcome-logo {
                font-size: 3rem;
            }
            
            .welcome-title {
                font-size: 2rem;
            }
            
            .welcome-subtitle {
                font-size: 1rem;
            }
            
            .welcome-btn {
                padding: 0.8rem 1.5rem;
                font-size: 1rem;
            }
        }

        @media (max-width: 480px) {
            .welcome-buttons {
                flex-direction: column;
                width: 80%;
            }
            
            .welcome-btn {
                width: 100%;
                justify-content: center;
            }
            
            .story {
                width: 70px;
                height: 110px;
            }
        }

        /* Animations */
        @keyframes pulse {
            0% {
                transform: scale(1);
            }
            50% {
                transform: scale(1.1);
            }
            100% {
                transform: scale(1);
            }
        }
    </style>
</head>
<body>
    <!-- Welcome Screen -->
    <div class="welcome-screen">
        <div class="welcome-logo">
            <i class="fas fa-users"></i>
        </div>
        <h1 class="welcome-title">مرحبًا بك في SocialVerse</h1>
        <p class="welcome-subtitle">منصة التواصل الاجتماعي التي تجمع العالم العربي معًا. شارك لحظاتك، تواصل مع الأصدقاء، واستكشف عالمًا من المحتوى المثير.</p>
        <div class="welcome-buttons">
            <button class="welcome-btn welcome-btn-primary" id="login-btn">
                <i class="fas fa-sign-in-alt"></i>
                تسجيل الدخول
            </button>
            <button class="welcome-btn welcome-btn-secondary" id="register-btn">
                <i class="fas fa-user-plus"></i>
                إنشاء حساب
            </button>
        </div>
    </div>

    <!-- Login Modal -->
    <div class="auth-modal" id="login-modal">
        <div class="auth-container">
            <div class="auth-header">
                <button class="close-auth" id="close-login">
                    <i class="fas fa-times"></i>
                </button>
                <h2 class="auth-title">تسجيل الدخول</h2>
                <p class="auth-subtitle">ادخل معلوماتك للوصول إلى حسابك</p>
            </div>
            <div class="auth-body">
                <div class="auth-form-group">
                    <label for="login-email">البريد الإلكتروني</label>
                    <input type="email" id="login-email" class="auth-form-control" placeholder="ادخل بريدك الإلكتروني">
                </div>
                <div class="auth-form-group">
                    <label for="login-password">كلمة المرور</label>
                    <input type="password" id="login-password" class="auth-form-control" placeholder="ادخل كلمة المرور">
                </div>
                <div class="auth-footer">
                    <button class="auth-submit-btn" id="login-submit">
                        تسجيل الدخول
                    </button>
                    <p class="auth-switch-text">
                        ليس لديك حساب؟
                        <button class="auth-switch-btn" id="switch-to-register">سجل الآن</button>
                    </p>
                </div>
            </div>
        </div>
    </div>

    <!-- Register Modal -->
    <div class="auth-modal" id="register-modal">
        <div class="auth-container">
            <div class="auth-header">
                <button class="close-auth" id="close-register">
                    <i class="fas fa-times"></i>
                </button>
                <h2 class="auth-title">إنشاء حساب جديد</h2>
                <p class="auth-subtitle">املأ النموذج لإنشاء حساب جديد</p>
            </div>
            <div class="auth-body">
                <div class="auth-form-group">
                    <label for="register-name">الاسم الك��مل</label>
                    <input type="text" id="register-name" class="auth-form-control" placeholder="ادخل اسمك الكامل">
                </div>
                <div class="auth-form-group">
                    <label for="register-email">البريد الإلكتروني</label>
                    <input type="email" id="register-email" class="auth-form-control" placeholder="ادخل بريدك الإلكتروني">
                </div>
                <div class="auth-form-group">
                    <label for="register-password">كلمة المرور</label>
                    <input type="password" id="register-password" class="auth-form-control" placeholder="اختر كلمة مرور قوية">
                </div>
                <div class="auth-form-group">
                    <label for="register-confirm-password">تأكيد كلمة المرور</label>
                    <input type="password" id="register-confirm-password" class="auth-form-control" placeholder="أعد إدخال كلمة المرور">
                </div>
                <div class="auth-footer">
                    <button class="auth-submit-btn" id="register-submit">
                        إنشاء حساب
                    </button>
                    <p class="auth-switch-text">
                        لديك حساب بالفعل؟
                        <button class="auth-switch-btn" id="switch-to-login">سجل الدخول</button>
                    </p>
                </div>
            </div>
        </div>
    </div>

    <!-- Main App -->
    <div class="app-container" id="app-container">
        <!-- Header -->
        <header class="app-header">
            <div class="logo">
                <i class="fas fa-users"></i>
                <span>SocialVerse</span>
            </div>
            <div class="header-actions">
                <div class="header-icon">
                    <i class="fas fa-search"></i>
                </div>
                <div class="header-icon">
                    <i class="fas fa-bell"></i>
                    <span class="notification-badge">3</span>
                </div>
                <div class="header-icon">
                    <i class="fas fa-envelope"></i>
                    <span class="notification-badge">5</span>
                </div>
                <img src="https://randomuser.me/api/portraits/men/32.jpg" alt="User" class="user-avatar">
            </div>
        </header>

        <!-- Stories -->
        <div class="stories-container">
            <div class="story add-story">
                <i class="fas fa-plus"></i>
                <span>إضافة قصة</span>
            </div>
            <div class="story">
                <img src="https://randomuser.me/api/portraits/women/44.jpg" alt="User" class="story-avatar">
                <span class="story-username">سارة</span>
            </div>
            <div class="story">
                <img src="https://randomuser.me/api/portraits/men/22.jpg" alt="User" class="story-avatar">
                <span class="story-username">أحمد</span>
            </div>
            <div class="story">
                <img src="https://randomuser.me/api/portraits/women/68.jpg" alt="User" class="story-avatar">
                <span class="story-username">نور</span>
            </div>
            <div class="story">
                <img src="https://randomuser.me/api/portraits/men/75.jpg" alt="User" class="story-avatar">
                <span class="story-username">محمد</span>
            </div>
            <div class="story">
                <img src="https://randomuser.me/api/portraits/women/33.jpg" alt="User" class="story-avatar">
                <span class="story-username">ليلى</span>
            </div>
            <div class="story">
                <img src="https://randomuser.me/api/portraits/men/55.jpg" alt="User" class="story-avatar">
                <span class="story-username">خالد</span>
            </div>
        </div>

        <!-- Feed -->
        <div class="feed-container">
            <!-- Post 1 -->
            <div class="post">
                <div class="post-header">
                    <img src="https://randomuser.me/api/portraits/women/44.jpg" alt="User" class="post-avatar">
                    <div class="post-user-info">
                        <div class="post-username">سارة محمد</div>
                        <div class="post-time">منذ ساعتين</div>
                    </div>
                    <div class="post-more">
                        <i class="fas fa-ellipsis-h"></i>
                    </div>
                </div>
                <div class="post-content">
                    <p class="post-text">
                        مرحبا بالجميع! هذه أول مشاركة لي على هذه المنصة الرائعة. أنا متحمسة للتعرف على أصدقاء جدد ومشاركة اهتماماتنا معًا. ما هي اهتماماتكم؟ 😊
                    </p>
                    <img src="https://source.unsplash.com/random/600x400" alt="Post" class="post-image">
                </div>
                <div class="post-actions">
                    <div class="post-action">
                        <i class="far fa-heart"></i>
                        <span>إعجاب</span>
                    </div>
                    <div class="post-action">
                        <i class="far fa-comment"></i>
                        <span>تعليق</span>
                    </div>
                    <div class="post-action">
                        <i class="fas fa-share"></i>
                        <span>مشاركة</span>
                    </div>
                </div>
                <div class="post-comments">
                    <div class="comment">
                        <img src="https://randomuser.me/api/portraits/men/22.jpg" alt="User" class="comment-avatar">
                        <div class="comment-content">
                            <div class="comment-username">أحمد علي</div>
                            <p class="comment-text">مرحبًا سارة! أنا مهتم بالتصوير الفوتوغرافي والسفر. هل لديك أي اهتمامات مشتركة؟</p>
                        </div>
                    </div>
                    <div class="add-comment">
                        <input type="text" class="comment-input" placeholder="أضف تعليقًا...">
                        <button class="comment-submit">
                            <i class="fas fa-paper-plane"></i>
                        </button>
                    </div>
                </div>
            </div>

            <!-- Post 2 -->
            <div class="post">
                <div class="post-header">
                    <img src="https://randomuser.me/api/portraits/men/55.jpg" alt="User" class="post-avatar">
                    <div class="post-user-info">
                        <div class="post-username">خالد عبدالله</div>
                        <div class="post-time">منذ 5 ساعات</div>
                    </div>
                    <div class="post-more">
                        <i class="fas fa-ellipsis-h"></i>
                    </div>
                </div>
                <div class="post-content">
                    <p class="post-text">
                        شاركت اليوم في ماراثون المدينة وكانت تجربة رائعة! أنصح الجميع بممارسة الرياضة بانتظام لفوائدها العديدة على الصحة الجسدية والنفسية. هل يمارس أحدكم الرياضة بانتظام؟
                    </p>
                    <img src="https://source.unsplash.com/random/600x401" alt="Post" class="post-image">
                </div>
                <div class="post-actions">
                    <div class="post-action liked">
                        <i class="fas fa-heart"></i>
                        <span>معجب</span>
                    </div>
                    <div class="post-action">
                        <i class="far fa-comment"></i>
                        <span>تعليق</span>
                    </div>
                    <div class="post-action">
                        <i class="fas fa-share"></i>
                        <span>مشاركة</span>
                    </div>
                </div>
                <div class="post-comments">
                    <div class="comment">
                        <img src="https://randomuser.me/api/portraits/women/33.jpg" alt="User" class="comment-avatar">
                        <div class="comment-content">
                            <div class="comment-username">ليلى أحمد</div>
                            <p class="comment-text">أحاول الجري ثلاث مرات أسبوعيًا، لكن لم أشارك في ماراثون بعد. أي نصائح للمبتدئين؟</p>
                        </div>
                    </div>
                    <div class="comment">
                        <img src="https://randomuser.me/api/portraits/men/55.jpg" alt="User" class="comment-avatar">
                        <div class="comment-content">
                            <div class="comment-username">خالد عبدالله</div>
                            <p class="comment-text">ابدأ بمسافات قصيرة وزدها تدريجيًا، واستمع لجسمك ولا تبالغ. الأهم هو الاستمرارية!</p>
                        </div>
                    </div>
                    <div class="add-comment">
                        <input type="text" class="comment-input" placeholder="أضف تعليقًا...">
                        <button class="comment-submit">
                            <i class="fas fa-paper-plane"></i>
                        </button>
                    </div>
                </div>
            </div>
        </div>

        <!-- Bottom Navigation -->
        <nav class="bottom-nav">
            <div class="nav-item active">
                <i class="fas fa-home nav-icon"></i>
                <span class="nav-text">الرئيسية</span>
            </div>
            <div class="nav-item">
                <i class="fas fa-search nav-icon"></i>
        
