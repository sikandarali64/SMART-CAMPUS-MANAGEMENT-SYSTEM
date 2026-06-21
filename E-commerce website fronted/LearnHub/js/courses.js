// ===== Course Data =====
const coursesData = [
    {
        id: 1,
        title: 'React - The Complete Guide',
        category: 'web',
        instructor: 'Sarah Anderson',
        rating: 4.8,
        reviews: 2456,
        duration: '48 hours',
        price: 79.99,
        level: 'beginner',
        image: '📚'
    },
    {
        id: 2,
        title: 'Python for Data Science',
        category: 'data',
        instructor: 'John Developer',
        rating: 4.9,
        reviews: 1823,
        duration: '56 hours',
        price: 89.99,
        level: 'intermediate',
        image: '🐍'
    },
    {
        id: 3,
        title: 'Web Design Masterclass',
        category: 'design',
        instructor: 'Emma Designer',
        rating: 4.7,
        reviews: 3124,
        duration: '40 hours',
        price: 69.99,
        level: 'beginner',
        image: '🎨'
    },
    {
        id: 4,
        title: 'iOS Development with Swift',
        category: 'mobile',
        instructor: 'Mike iOS Dev',
        rating: 4.6,
        reviews: 1245,
        duration: '52 hours',
        price: 84.99,
        level: 'intermediate',
        image: '📱'
    },
    {
        id: 5,
        title: 'Advanced JavaScript',
        category: 'web',
        instructor: 'Alex JS Master',
        rating: 4.9,
        reviews: 2890,
        duration: '44 hours',
        price: 74.99,
        level: 'advanced',
        image: '⚙️'
    },
    {
        id: 6,
        title: 'Machine Learning Basics',
        category: 'data',
        instructor: 'Dr. AI Expert',
        rating: 4.8,
        reviews: 1567,
        duration: '60 hours',
        price: 99.99,
        level: 'advanced',
        image: '🤖'
    },
    {
        id: 7,
        title: 'DevOps Fundamentals',
        category: 'devops',
        instructor: 'Cloud Master',
        rating: 4.7,
        reviews: 987,
        duration: '48 hours',
        price: 79.99,
        level: 'intermediate',
        image: '☁️'
    },
    {
        id: 8,
        title: 'UI/UX Design Principles',
        category: 'design',
        instructor: 'Creative Pro',
        rating: 4.8,
        reviews: 2345,
        duration: '35 hours',
        price: 64.99,
        level: 'beginner',
        image: '🎯'
    },
    {
        id: 9,
        title: 'Angular - Complete Course',
        category: 'web',
        instructor: 'Framework Expert',
        rating: 4.6,
        reviews: 1678,
        duration: '50 hours',
        price: 79.99,
        level: 'intermediate',
        image: '🔴'
    },
    {
        id: 10,
        title: 'Database Design',
        category: 'data',
        instructor: 'DB Specialist',
        rating: 4.7,
        reviews: 1456,
        duration: '42 hours',
        price: 74.99,
        level: 'intermediate',
        image: '🗄️'
    },
    {
        id: 11,
        title: 'Android Development',
        category: 'mobile',
        instructor: 'Android Pro',
        rating: 4.5,
        reviews: 1234,
        duration: '55 hours',
        price: 84.99,
        level: 'intermediate',
        image: '🟢'
    },
    {
        id: 12,
        title: 'Cloud Architecture',
        category: 'devops',
        instructor: 'AWS Expert',
        rating: 4.8,
        reviews: 2100,
        duration: '54 hours',
        price: 94.99,
        level: 'advanced',
        image: '☁️'
    }
];

let filteredCourses = [...coursesData];
let currentPage = 1;
const coursesPerPage = 6;

// ===== Initialize Courses Page =====
document.addEventListener('DOMContentLoaded', () => {
    renderCourses();
    setupFilters();
    setupSorting();
});

// ===== Render Courses =====
function renderCourses() {
    const coursesGrid = document.getElementById('coursesGrid');
    const courseCount = document.getElementById('courseCount');
    
    if (!coursesGrid) return;
    
    const startIndex = (currentPage - 1) * coursesPerPage;
    const endIndex = startIndex + coursesPerPage;
    const paginatedCourses = filteredCourses.slice(startIndex, endIndex);
    
    courseCount.textContent = filteredCourses.length;
    
    coursesGrid.innerHTML = paginatedCourses.map(course => `
        <div class="course-card" data-aos="fade-up">
            <div class="course-image">
                <div class="course-image-placeholder" style="background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);">
                    ${course.image}
                </div>
                <span class="course-badge">${course.level.charAt(0).toUpperCase() + course.level.slice(1)}</span>
            </div>
            <div class="course-info">
                <span class="course-category">${getCategoryLabel(course.category)}</span>
                <h3>${course.title}</h3>
                <p class="course-instructor">
                    <i class="fas fa-user-circle"></i> ${course.instructor}
                </p>
                <div class="course-meta">
                    <span class="rating">
                        <i class="fas fa-star"></i> ${course.rating} (${course.reviews.toLocaleString()})
                    </span>
                    <span class="duration">
                        <i class="fas fa-clock"></i> ${course.duration}
                    </span>
                </div>
                <div class="course-price">
                    <span class="price">$${course.price}</span>
                </div>
                <button class="btn btn-primary btn-block">Enroll Now</button>
            </div>
        </div>
    `).join('');
    
    updatePagination();
}

// ===== Setup Filters =====
function setupFilters() {
    const categoryFilters = document.querySelectorAll('.category-filter');
    const priceFilters = document.querySelectorAll('.price-filter');
    const ratingFilters = document.querySelectorAll('.rating-filter');
    const levelFilters = document.querySelectorAll('.level-filter');
    const searchInput = document.getElementById('searchInput');
    const resetBtn = document.getElementById('resetFilters');
    
    categoryFilters.forEach(filter => {
        filter.addEventListener('change', applyFilters);
    });
    
    priceFilters.forEach(filter => {
        filter.addEventListener('change', applyFilters);
    });
    
    ratingFilters.forEach(filter => {
        filter.addEventListener('change', applyFilters);
    });
    
    levelFilters.forEach(filter => {
        filter.addEventListener('change', applyFilters);
    });
    
    if (searchInput) {
        searchInput.addEventListener('input', applyFilters);
    }
    
    if (resetBtn) {
        resetBtn.addEventListener('click', resetFilters);
    }
}

// ===== Apply Filters =====
function applyFilters() {
    const categoryChecked = Array.from(document.querySelectorAll('.category-filter:checked')).map(el => el.value);
    const searchTerm = document.getElementById('searchInput')?.value.toLowerCase() || '';
    
    filteredCourses = coursesData.filter(course => {
        // Category filter
        if (categoryChecked.includes('all') || categoryChecked.length === 0) {
            return true;
        }
        if (!categoryChecked.includes(course.category)) return false;
        
        // Search filter
        if (searchTerm && !course.title.toLowerCase().includes(searchTerm)) {
            return false;
        }
        
        return true;
    });
    
    currentPage = 1;
    renderCourses();
}

// ===== Reset Filters =====
function resetFilters() {
    document.querySelectorAll('.category-filter').forEach(el => {
        el.checked = el.value === 'all';
    });
    document.querySelectorAll('.price-filter').forEach(el => {
        el.checked = el.value === 'all';
    });
    document.querySelectorAll('.rating-filter').forEach(el => {
        el.checked = false;
    });
    document.querySelectorAll('.level-filter').forEach(el => {
        el.checked = false;
    });
    document.getElementById('searchInput').value = '';
    
    filteredCourses = [...coursesData];
    currentPage = 1;
    renderCourses();
}

// ===== Setup Sorting =====
function setupSorting() {
    const sortSelect = document.getElementById('sortSelect');
    if (sortSelect) {
        sortSelect.addEventListener('change', (e) => {
            const sortType = e.target.value;
            
            switch(sortType) {
                case 'rating':
                    filteredCourses.sort((a, b) => b.rating - a.rating);
                    break;
                case 'newest':
                    filteredCourses.reverse();
                    break;
                case 'price-low':
                    filteredCourses.sort((a, b) => a.price - b.price);
                    break;
                case 'price-high':
                    filteredCourses.sort((a, b) => b.price - a.price);
                    break;
                default:
                    filteredCourses.sort((a, b) => b.reviews - a.reviews);
            }
            
            currentPage = 1;
            renderCourses();
        });
    }
}

// ===== Pagination =====
function updatePagination() {
    const totalPages = Math.ceil(filteredCourses.length / coursesPerPage);
    const paginationNumbers = document.getElementById('paginationNumbers');
    const prevBtn = document.getElementById('prevBtn');
    const nextBtn = document.getElementById('nextBtn');
    
    if (!paginationNumbers) return;
    
    paginationNumbers.innerHTML = '';
    
    for (let i = 1; i <= totalPages; i++) {
        const btn = document.createElement('button');
        btn.className = `pagination-btn ${i === currentPage ? 'active' : ''}`;
        btn.textContent = i;
        btn.addEventListener('click', () => {
            currentPage = i;
            renderCourses();
            window.scrollTo({ top: 0, behavior: 'smooth' });
        });
        paginationNumbers.appendChild(btn);
    }
    
    if (prevBtn) {
        prevBtn.addEventListener('click', () => {
            if (currentPage > 1) {
                currentPage--;
                renderCourses();
                window.scrollTo({ top: 0, behavior: 'smooth' });
            }
        });
    }
    
    if (nextBtn) {
        nextBtn.addEventListener('click', () => {
            if (currentPage < totalPages) {
                currentPage++;
                renderCourses();
                window.scrollTo({ top: 0, behavior: 'smooth' });
            }
        });
    }
}

// ===== Helper Functions =====
function getCategoryLabel(category) {
    const labels = {
        'web': 'Web Development',
        'data': 'Data Science',
        'design': 'UI/UX Design',
        'mobile': 'Mobile Development',
        'devops': 'DevOps & Cloud'
    };
    return labels[category] || category;
}