// ===== Dashboard Navigation =====
document.addEventListener('DOMContentLoaded', () => {
    const navItems = document.querySelectorAll('.sidebar-nav .nav-item');
    const sidebarToggle = document.getElementById('sidebarToggle');
    const sidebar = document.getElementById('sidebar');
    const sidebarClose = document.getElementById('sidebarClose');
    
    // Navigation
    navItems.forEach(item => {
        item.addEventListener('click', (e) => {
            e.preventDefault();
            
            const section = item.getAttribute('data-section');
            
            // Remove active from all
            navItems.forEach(n => n.classList.remove('active'));
            document.querySelectorAll('.dashboard-content section').forEach(s => {
                s.style.display = 'none';
            });
            
            // Add active to clicked
            item.classList.add('active');
            const target = document.getElementById(section);
            if (target) {
                target.style.display = 'block';
            }
        });
    });
    
    // Sidebar toggle
    if (sidebarToggle) {
        sidebarToggle.addEventListener('click', () => {
            sidebar.classList.toggle('active');
        });
    }
    
    if (sidebarClose) {
        sidebarClose.addEventListener('click', () => {
            sidebar.classList.remove('active');
        });
    }
    
    // Close sidebar when clicking outside
    document.addEventListener('click', (e) => {
        if (!e.target.closest('.sidebar-nav') && 
            !e.target.closest('.sidebar-toggle') &&
            sidebar) {
            sidebar.classList.remove('active');
        }
    });
});

// ===== Profile Dropdown =====
document.addEventListener('DOMContentLoaded', () => {
    const profileDropdown = document.querySelector('.profile-dropdown');
    const profileBtn = document.querySelector('.profile-btn');
    
    if (profileBtn && profileDropdown) {
        profileBtn.addEventListener('click', (e) => {
            e.preventDefault();
            profileDropdown.classList.toggle('active');
        });
        
        document.addEventListener('click', (e) => {
            if (!e.target.closest('.profile-dropdown')) {
                profileDropdown.classList.remove('active');
            }
        });
    }
});